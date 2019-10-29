#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        LL ans = 0;
        LL left = 0;
        LL a;
        for(int i = 0; i < n; i++) {
            cin >> a;
            left += a;
            ans += abs(left);
        }
        cout << ans << endl;
    }
    return 0;
}