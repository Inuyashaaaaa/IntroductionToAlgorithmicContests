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
    cin >> n;
    string s;
    cin >> s;
    int _left = 0;
    int _right = 0;
    int start = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') _left++;
        if(s[i] == ')') _right++;
        if(_left == _right) {
            if(s[i] == '(') {
                ans += i - start;
            }
            start = i;
        }
    }
    // cout << ans << endl;
    if(_left == _right)
        cout << ans << endl;
    else 
        cout << -1 << endl;
    return 0;
}