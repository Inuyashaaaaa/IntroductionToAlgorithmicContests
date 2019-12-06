#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int sz = s.size();
        for(int i = 0; i < sz; i++) {
            if(s[i] == '?') {
                int a[3];
                ms(a);
                if(i) {
                    a[s[i - 1] - 'a'] = 1;
                }
                if(i != sz - 1) {
                    if(s[i + 1] != '?') { 
                        a[s[i + 1] - 'a'] = 1;
                    }
                }
                if(!a[0]) s[i] = 'a';
                else if(!a[1]) s[i] = 'b';
                else if(!a[2]) s[i] = 'c';
            }
        }
        bool ok = true;
        for(int i = 0; i < sz - 1; i++) {
            if(s[i] == s[i + 1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? s : "-1") << endl;
    }
    return 0;
}