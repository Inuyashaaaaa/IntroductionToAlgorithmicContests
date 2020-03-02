#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;
int _left[maxn];
int _right[maxn];
char s[maxn];

void del(int i) {
    _left[_right[i]] = _left[i];
    _right[_left[i]] = _right[i];
    _left[i] = -1;
    _right[i] = -1; 
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i < maxn; i++) {
        _left[i] = i - 1;
        _right[i] = i + 1;
    }
    int n;
    cin >> n;
    cin >> (s + 1);
    s[0] = '0';
    s[n + 1] = '0';
    // cout << s << endl;
    int ans = 0;
    for(int k = 25; k >= 0; k--) {
        char ch = k + 'a';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[j] != ch) continue;
                if(_left[j] == -1) continue;
                if(s[_left[j]] == ch - 1 || s[_right[j]] == ch - 1) {
                    del(j);
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}