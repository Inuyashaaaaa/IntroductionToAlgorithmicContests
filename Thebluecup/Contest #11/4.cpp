#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while(cin >> s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans *= 2;
            ans += s[i] - '0';
        }
        cout << ans << endl;
    }
    return 0;
}