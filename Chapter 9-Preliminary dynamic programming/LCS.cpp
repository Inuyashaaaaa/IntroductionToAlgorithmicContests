#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e4 + 10;

int a[maxn];
int b[maxn];
int n, m;
int len = 0;
string ans;

void dp(int i, int j, string ret) {
    if(i == 0 || j == 0) {
        if(ret.length() >= ans.length()) {
            ans = ret;
        }
        return;
    } 
    if(a[i] == b[j]) {
        ret += a[i] + '0';
        dp(i - 1, j - 1, ret);
    } else {
        dp(i - 1, j, ret);
        dp(i, j - 1, ret);
    } 
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    dp(n, m, "");
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}