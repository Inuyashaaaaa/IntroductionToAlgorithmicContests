#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 3.5e3 + 10;
int a[maxn];
int sum[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        m--;
        if(k > m) {
            k = m;
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i <= m; i++) {
            sum[i] = max(a[i], a[n - m + i - 1]);
        }
        int ans = 0;
        for(int i = 0; i <= k; i++) {
            int minn = 1000000000;
            for(int j = i; j <= m - k + i; j++) {
                minn = min(minn, sum[j]);
            }
            ans = max(ans, minn);
        }
        cout << ans << endl;
    }
    return 0;
}