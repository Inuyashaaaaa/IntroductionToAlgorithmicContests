#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 100000000
using namespace std;
const int TMAX = 200 + 10;  //时间
const int SMAX = 50 + 10;   //车站

// 在时间为 t 时刻 s车站 需要等待多久时间
int dp[TMAX][SMAX];

// 在时间为 t 时刻 s车站 是否有列车可以搭乘
bool haveTrain[TMAX][SMAX][2]; 

// 车站相隔时间
int t[SMAX];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, T;
    int kase = 0;
    while(cin >> n && n) {
        cin >> T;
        for(int i = 1; i <= n - 1; i++) {
            cin >> t[i]; //means i -> i + 1
        }
        int M1, M2, x;
        cin >> M1;
        ms(haveTrain);
        while(M1--) {
            cin >> x;
            for(int i = 1; i <= n - 1; i++) {
                if(x <= T) {
                    haveTrain[x][i][0] = 1;
                }
                x += t[i];
            }
        }
        cin >> M2;
        while(M2--) {
            cin >> x;
            for(int i = n - 1; i >= 1; i--) {
                if(x <= T) {
                    haveTrain[x][i + 1][1] = 1;
                }
                x += t[i];
            }
        }

        //DP
        for(int i = 1; i <= n - 1; i++) dp[T][i] = INF;
        dp[T][n] = 0;
        for(int i = T - 1; i >= 0; i--) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i + 1][j] + 1; //等一分钟
                if(j != n && haveTrain[i][j][0] && t[j] + i <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
                } // => 向右开
                if(j != 1 && haveTrain[i][j][1] && t[j - 1] + i <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
                }
            }
        }

        cout << "Case Number " << ++kase << ": ";
        if(dp[0][1] >= INF) cout << "impossible" << endl;
        else cout << dp[0][1] << endl;
    }
    return 0;
}