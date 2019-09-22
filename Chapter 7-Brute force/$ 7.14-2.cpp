#include<bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y;
    Cell(int x = 0, int y = 0):x(x), y(y) {};
    friend bool operator < (const Cell& c1, const Cell& c2) {
        return c1.x < c2.x || (c1.x == c2.x && c1.y < c2.y);
    }
};

typedef set<Cell> Polyomino;

Polyomino normalize(const Polyomino &p) {
    int minx = p.begin() -> x;
    int miny = p.begin() -> y;
    for(auto& c: p) {
        minx = min(minx, c.x);
        miny = min(miny, c.y);
    }
    Polyomino p2;
    for(auto& c: p) {
        p2.insert(Cell(c.x - minx, c.y - miny));
    }
    return p2;
}

Polyomino rotate(const Polyomino &p) {
    Polyomino p2;
    for(auto& c:p) {
        p2.insert(Cell(c.y, -c.x));
    }
    return normalize(p2);
}

Polyomino flip(const Polyomino &p) {
    Polyomino p2;
    for(auto& c:p) {
        p2.insert(Cell(c.x, -c.y));
    }
    return normalize(p2);
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int maxn = 10;

set<Polyomino> poly[maxn + 1];
int ans[maxn + 1][maxn + 1][maxn + 1];

void checkPolyomino(const Polyomino& p0, const Cell& c) {
    Polyomino p = p0;
    p.insert(c);
    p = normalize(p);

    int n = p.size();
    for(int i = 0; i < 4; i++) {
        if(poly[n].count(p)) return;
        p = rotate(p);
    }
    p = flip(p);
    for(int i = 0; i < 4; i++) {
        if(poly[n].count(p)) return;
        p = rotate(p);
    }
    poly[n].insert(p);
}

void generate() {
    Polyomino s;
    s.insert(Cell(0, 0));
    poly[1].insert(s);

    for(int n = 2; n <= maxn; n++) {
        for(auto& p: poly[n - 1]) {
            for(auto& c: p) {
                for(int dir = 0; dir < 4; dir++) {
                    Cell newc(c.x + dx[dir], c.y + dy[dir]);
                    if(p.count(newc) == 0) checkPolyomino(p, newc);
                }
            }
        }
    }

    for(int n = 1; n <= maxn; n++) {
        for(int w = 1; w <= maxn; w++) {
            for(int h = 1; h <= maxn; h++) {
                int cnt = 0;
                for(auto& p: poly[n]) {
                    int maxX = 0;
                    int maxY = 0;
                    for(auto& c: p) {
                        maxX = max(maxX, c.x);
                        maxY = max(maxY, c.y);
                    }
                    if(min(maxX, maxY) < min(h, w) 
                    && max(maxX, maxY) < max(h, w)) {
                        ++cnt;
                    }
                }
                ans[n][w][h] = cnt;
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    generate();
    int n, w, h;
    while(cin >> n >> w >> h) {
        cout << ans[n][w][h] << endl;
    }
    return 0;
}