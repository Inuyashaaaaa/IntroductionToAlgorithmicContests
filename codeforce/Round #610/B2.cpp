#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e5 + 10;
int w[maxn];
int dp[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n, p, k;
    while(T--) {
        cin >> n >> p >> k;
        for(int i = 1 ; i <= n; i++) {
            cin >> w[i];
        }
        ms(dp);
        sort(w + 1, w + 1 + n);
        for(int i = 1; i <= n; i++) {
            if(i < k) {
                dp[i] = dp[i - 1] + w[i];
            }
            else {
                dp[i] = dp[i - k] + w[i];
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dp[i] <= p) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}