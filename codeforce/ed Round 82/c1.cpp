#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
bool _use[26];
char ch[100];

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
        ms(_use);
        ms(ch);
        ch[50] = s[0];
        int pos = 50;
        _use[s[0] - 'a'] = 1;
        bool flag = false;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ch[pos]) {
                flag = true;
                break;
            }
            if(s[i] == ch[pos - 1]) {
                pos -= 1;
                continue;
            }
            if(s[i] == ch[pos + 1]) {
                pos += 1;
                continue;
            }
            if(_use[s[i] - 'a']) {
                flag = 1;
                break;
            } 
            if(!ch[pos + 1]) {
                ch[pos + 1] = s[i];
                _use[s[i] - 'a'] = true;
                pos++;
            }
            else if(!ch[pos - 1]) {
                ch[pos - 1] = s[i];
                _use[s[i] - 'a'] = true;
                pos--;
            }
            else {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for(int i = 0; i < 100; i++) {
                if(ch[i]) cout << ch[i];
            }
            for(int i = 0; i < 26; i++) {
                if(!_use[i]) cout << char(i + 'a');
            }
            cout << endl;
        }
    }
    return 0;
}