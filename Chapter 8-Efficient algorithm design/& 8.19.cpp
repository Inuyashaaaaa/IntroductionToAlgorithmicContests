#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
int len;
int xx, yy;

struct Point {
    int x, y;
    Point(int x, int y):x(x), y(y) {}
    friend bool operator < (const Point &p1, const Point& p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    }
    friend bool operator == (const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

set<int> s; //y集合
vector<Point> vec;

void solve(int w) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(auto it1 = s.begin(); it1 != s.end(); ) {
        int ymin = *it1;
        for(auto it2 = ++it1; it2 != s.end(); it2++) {
            int ymax = *it2;
            int left = 0;
            for(auto p: vec) {
                if(p.y <= ymin || p.y >= ymax) {
                    continue;
                }
                if(len < min(ymax - ymin, p.x - left)) {
                    len = min(ymax - ymin, p.x - left);
                    xx = left;
                    yy = ymin;
                }
                left = p.x;
            }
            //考虑最后一个
            if(len < min(ymax - ymin, w - left)) {
                len = min(ymax - ymin, w - left);
                xx = left;
                yy = ymin;
            }
        }
    }
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
        if(kase++) cout << endl;
        int N, W, H;
        int x, y;
        cin >> N >> W >> H;
        len = -1;
        vec.clear();
        s.clear();
        s.insert(0);
        s.insert(H);
        while(N--) {
            cin >> x >> y;
            s.insert(y);
            vec.push_back(Point(x, y));
        }
        solve(W);
        cout << xx << " " << yy << " " << len << endl;
    }
    return 0;
}