#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
int n;

struct Point {
    int x, y;
    bool color; // 0 means white and 1 means black
    double rad;
    friend bool operator < (const Point& p1,const Point& p2) {
        return p1.rad < p2.rad;
    }
}p[maxn], op[maxn];

bool left(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x >= 0;
}

int solve() {
    if(n <= 2) return 2;
    int ans = 0;

    for(int i = 0; i < n ;i++) {
        int k = 0;

        // 以第i个视为基准点
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            p[k].x = op[j].x - op[i].x;
            p[k].y = op[j].y - op[i].y;
            if(op[j].color) {
                p[k].x = -p[k].x;
                p[k].y = -p[k].y;
            }
            p[k].rad = atan2(p[k].y, p[k].x);
            k++;
        }
        sort(p, p + k);
        int L = 0, R = 0, cnt = 2;
        while(L < k) {
            if(R == L) {
                R = (R + 1) % k;
                cnt++;
            }   
            //means contain 180 degrees
            while(R != L && left(p[L], p[R])) {
                R = (R + 1) % k;
                cnt++;
            }
            cnt--;
            L++;
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n) {
        for(int i = 0; i < n; i++) {
            cin >> op[i].x >> op[i].y >> op[i].color;
        }
        cout << solve() << endl;
    }    
    return 0;
}