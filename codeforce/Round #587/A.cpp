#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i+=2) {
        if(s[i] == s[i + 1]) {
            if(s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
            cnt++;
       }
    }
    cout << cnt << endl;
    cout << s << endl;
    
    return 0;
}