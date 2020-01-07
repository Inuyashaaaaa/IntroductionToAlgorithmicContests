#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    LL ans = 0;
    int c[2] = {};
    for(int i = 0; i < n ; i++) {
        cin >> x;
        ans += x / 2;
        if(x % 2 == 1) {
            c[i % 2]++;
        }
    }
    cout << ans + min(c[0], c[1]) << endl;
    return 0;
}