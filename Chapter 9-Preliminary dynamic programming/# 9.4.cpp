#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 10 + 5;
const int maxm = 100 + 5;
int G[maxn][maxm];
int dp[maxm][maxn];
int _next[maxm][maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> G[i][j];
            }
        }
        int first = 0;
        int ans = INF;
        for(int i = m; i >= 1; i--) { //列
            for(int j = 1; j <= n; j++) {
                if(i == m) {
                    dp[i][j] = G[j][i];
                }
                else {
                    int dir[] = {j - 1, j, j + 1};
                    if(j == 1) dir[0] = n;
                    if(j == n) dir[2] = 1;
                    sort(dir, dir + 3);
                    dp[i][j] = INF;
                    for(int k = 0; k < 3; k++) {
                        int v = dp[i + 1][dir[k]] + G[j][i];
                        if(v < dp[i][j]) {
                            dp[i][j] = v;
                            _next[i][j] = dir[k];
                        } 
                    }
                }
                if(i == 1 && dp[i][j] < ans) {
                    ans = dp[i][j];
                    first = j;
                }
            }   
        }
        cout << first;
        for(int i = _next[1][first], j = 1; j < m; j++, i = _next[j][i]) {
            cout << " " << i;
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}