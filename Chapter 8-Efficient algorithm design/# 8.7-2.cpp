#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int last[maxn];

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
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!m.count(a[i])) {
                last[i] = -1;
            } else {
                last[i] = m[a[i]];
            }
            m[a[i]] = i;
        }

        int L = 0, R = 0, ans = 0;
        while(R < n) {
            while(R < n && last[R] < L) {
                R++;
            }
            ans = max(ans, R - L);
            L++;
        }
        cout << ans << endl;
    }
    return 0;
}