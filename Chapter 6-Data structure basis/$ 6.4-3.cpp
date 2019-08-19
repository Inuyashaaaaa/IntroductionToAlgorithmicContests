#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;

int cur, last, Next[maxn];
char s[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> s + 1) {
        cur = last = 0;
        int len = strlen(s + 1);
        Next[0] = 0;
        for(int i = 1; i <= len; i++) {
            if(s[i] == '[') cur = 0;
            else if(s[i] == ']') cur = last;
            else {
                Next[i] = Next[cur];
                Next[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
            cout << "cur:" << cur << " last:" << last << endl;
        }
    }
    for(int i = 0 ; i <= strlen(s + 1) ;i ++) {
        cout << i << ": " << Next[i] << endl;
    }
    for(int i = Next[0]; i != 0; i = Next[i]) {
        cout << s[i] ;
    }
    cout << endl;
}