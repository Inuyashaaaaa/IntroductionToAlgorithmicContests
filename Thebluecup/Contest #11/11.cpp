#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

bool check(string s, int l, int r) {
    string s1 = s.substr(l, r - l);
    stringstream ss(s);
    
}

bool dfs(string s, int l, int r) {
    if(check(s, l, r)) return false;
    for(int i = l; i < r; i++) {
        if(s[i] == '?' && i + 1 < r && s[i + 1] != ',') {
            s[i] = ',';
            if(dfs(s, i + 1, r)) return true;
            s[i] = '?';
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    dfs(s, 0, s.size());
    return 0;
}