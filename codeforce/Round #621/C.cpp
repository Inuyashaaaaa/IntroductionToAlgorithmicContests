#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
LL a[26];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sz = s.size();
    // aabaa
    LL ans = -1;
    for(int i = 0; i < sz; i++) {
        a[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        ans = max(ans, a[i]);
        ans = max(ans, a[i] * (a[i] - 1) / 2);
    }
    // cout << ans << endl;
    for(int i = 0; i < 26; i++) {
        char c = i + 'a';
        for(int j = 0; j < 26; j++) {
            char b = j + 'a';
            if(c == b) continue;
            LL cntA = 0;
            LL cntB = a[j];
            bool first = true;
            LL temp = 0;
            for(int k = 0; k < sz; k++) {
                if(s[k] == c) {
                    temp += cntB;
                }
                if(s[k] == b) {
                    cntB--;
                }
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}