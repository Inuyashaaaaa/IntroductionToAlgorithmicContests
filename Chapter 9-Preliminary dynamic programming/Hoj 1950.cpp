#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 4e4 + 10;
int a[maxn];
int len[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ans = 1;
        len[1] = a[1];
        for(int i = 2; i <= n; i++) {
            if(a[i] > len[ans]) {
                ans++;
                len[ans] = a[i];
            }
            else {
                int pos = lower_bound(len + 1, len + ans + 1, a[i]) - len;
                len[pos] = a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}