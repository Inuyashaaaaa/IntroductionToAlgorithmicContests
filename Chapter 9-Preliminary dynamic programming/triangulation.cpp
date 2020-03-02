#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X1fffffff
using namespace std;
const int maxn = 1e2 + 10;
int d[maxn][maxn];
int dp[maxn][maxn];
int n;

int solve(int i, int j) {
    if(i + 1 == j) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = INF;
    for(int k = i + 1; k < j; k++) {
        ans = min(ans, solve(i, k) + solve(k, j) + d[i][j] + d[i][k] + d[j][k]);
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    cout << solve(1, 6) << endl;
    
    return 0;
}