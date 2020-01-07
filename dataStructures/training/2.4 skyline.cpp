#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 6e3 + 10;
int height[maxn];

// n n <= 4000
// li hi ri -3000 <= Li，Ri<= 3000， 1 <= Hi <= 1000



int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ms(height);
    for(int i = 0; i < n; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        l += 3000;
        r += 3000;
        for(int i = l; i < r; i++) {
            if(h > height[i])
            height[i] = h;
        }
    }
    for(int i = 0; i < maxn - 1; i++) {
        if(height[i] != height[i + 1]) {
            cout << i - 2999 << " " << height[i + 1] << " ";
        }
    }
    return 0;
}