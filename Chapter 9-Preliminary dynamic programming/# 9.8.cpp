#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
int num[26];
int cnt[maxn][maxn][26];

const int maxn = 5e3 + 10;
int dp[maxn][maxn];
int cont[maxn][maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ms(num); 
        ms(cnt[0][0]);
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        for(int i = 0; i < n; i++) {
            num[s1[i] - 'A']++;
        }
        for(int i = 0; i < m; i++) {
            num[s2[i] - 'A']++;
        }
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = 10001;
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = 0;
                    cont[0][0] = 0; //开始还未结束的
                    continue;
                }
        
                if(i == 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + cont[i][j - 1]);
                    int index = s2[j - 1] - 'A';
                    if(cnt[i][j - 1][index] == 0) cont[i][j] = cont[i][j - 1] + 1;
                    if(++cnt[i][j - 1][index] == num[index]) cont[i][j] = cont[i][j - 1] - 1;
                    continue;
                }      
                if(j == 0) {
                    dp[i][j] = min(dp[i - 1][j] + cont[i - 1][j], dp[i][j]);
                    int index = s1[i - 1] - 'A';
                    if(cnt[i - 1][j][index] == 0) cont[i][j] = cont[i - 1][j] + 1;
                    if(++cnt[i - 1][j][index] == num[index]) cont[i][j] = cont[i - 1][j] - 1;
                    continue;
                } 
                int num1, num2;
                num1 = dp[i][j - 1] + cont[i][j - 1];
                num2 = dp[i - 1][j] + cont[i - 1][j];
                if(num1 < num2) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + cont[i][j - 1]);
                    int index = s2[j - 1] - 'A';
                    if(cnt[i][j - 1][index] == 0) cont[i][j] = cont[i][j - 1] + 1;
                    if(++cnt[i][j - 1][index] == num[index]) cont[i][j] = cont[i][j - 1] - 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j] + cont[i - 1][j], dp[i][j]);
                    int index = s1[i - 1] - 'A';
                    if(cnt[i - 1][j][index] == 0) cont[i][j] = cont[i - 1][j] + 1;
                    if(++cnt[i - 1][j][index] == num[index]) cont[i][j] = cont[i - 1][j] - 1;
                }
            }
        }
        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}