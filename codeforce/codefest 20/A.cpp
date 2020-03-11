#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans += a[i];
        }
        cout << min(ans + a[0], m) << endl;
    }
    return 0;
}