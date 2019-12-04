#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    while(cin >> n >> d && n && d) {
        string s;
        cin >> s;
        int ele = n - d;
        string ans;
        ans.resize(maxn);
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            while(d && pos && ch > ans[pos - 1]) {
                pos--;
                d--;
            }
            ans[pos++] = ch;
        }
        ans.resize(ele);
        cout << ans << endl;
    }
    return 0;
}