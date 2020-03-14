#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--) {
        string s;
        cin >> s;
        int sz = s.size();
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < sz; i++) {
            if(s[i] == 'L') {
                cnt++;
            } 
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        cnt = 0;
        cout << ans + 1 << endl;
    }
    return 0;
}