#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e3 + 10;
int is_pal[maxn][maxn]; 
int dp[maxn];
int kase;
string s;

int check(int i, int j) {
    if(i >= j) return kase;
    if(s[i] != s[j]) return 0;
    if(is_pal[i][j] == kase) return kase;
    is_pal[i][j] = check(i + 1, j - 1);
    return is_pal[i][j];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(kase = 1; kase <= T; kase++) {
        cin >> s;
        int sz = s.size();
        for(int i = 0; i < maxn; i++) {
            dp[i] = maxn;
        }
        dp[0] = 0;
        for(int i = 1; i <= sz; i++) {
            for(int j = i; j <= sz; j++) {
                if(check(i - 1, j - 1) == kase) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        cout << dp[sz] << endl; 
    }
    return 0;
}