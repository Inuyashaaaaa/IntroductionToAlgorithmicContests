#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e3 + 10;
char g[maxn][maxn];

struct Circle {
    int r, x, y;
    Circle(int r, int x, int y):r(r), x(x), y(y){}
    friend bool operator < (const Circle& c1, const Circle& c2) {
        return c1.r == c2.r ? (c1.x == c2.x ? 
        c1.y < c2.y : c1.x < c2.x) : c1.r < c2.r;
    }
    friend ostream& operator << (ostream& out, Circle& c) {
        out << "(" << c.r << "," << c.x << "," << c.y << ")";
        return out;
    }
};

bool check(int y, int x, int r) {
    int cnt = 0;
    for(int i = 0; i <= r; i++) {
        int dy = (int)(sqrt(r * r - i * i) + 0.5);
        if(!g[x - i][y + dy]) cnt++;
        if(!g[x + i][y + dy]) cnt++;
        if(!g[x - i][y - dy]) cnt++;
        if(!g[x + i][y - dy]) cnt++;
        if(cnt >= 5) return false;
    }
    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        int w, h;
        cin >> w >> h;
        ms(g);
        REP(i, 0, h)
            REP(j, 0, w) {
                cin >> g[i][j];
                g[i][j] -= '0';
            }
        int maxr = min(w, h) >> 1;
        vector<Circle> ans;
        for(int r = 5; r <= maxr; r++) {
            for(int i = r; i < w - r; i++) {
                for(int j = r; j < h - r; j++) {
                    if(check(i, j, r)) {
                        ans.push_back(Circle(r, i, j));
                    }
                }
            } 
        }
        cout << "Case " << ++kase << ": " << ans.size();
        for(auto& c: ans) cout << " " << c;
        cout << endl;
   } 
    return 0;
}