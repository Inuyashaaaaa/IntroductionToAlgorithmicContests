#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X3fffffff
using namespace std;

const int maxn = 5e3 + 10;
int startt[26][2];
int endd[26][2];
int cnt[maxn][maxn];
int dp[maxn][maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        memset(startt, -1, sizeof(startt));
        memset(endd, -1, sizeof(endd));
        for(int i = 0; i < n; i++) {
            int index = s1[i] - 'A';
            if(startt[index][0] == -1) {
                startt[index][0] = i;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int index = s1[i] - 'A';
            if(endd[index][0] == -1) {
                endd[index][0] = i;
            }
        }
        for(int i = 0; i < m; i++) {
            int index = s2[i] - 'A';
            if(startt[index][1] == -1) {
                startt[index][1] = i;
            }
        }
        for(int i = m - 1; i >= 0; i--) {
            int index = s2[i] - 'A';
            if(endd[index][1] == -1) {
                endd[index][1] = i;
            }
        }

        cnt[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i) {
                    cnt[i][j] = cnt[i - 1][j];
                    int index = s1[i - 1] - 'A'; //取走第一个序列第i个 （下标i-1
                    if(startt[index][0] == i - 1 && (startt[index][1] > j - 1 || startt[index][1] == -1)) {
                        cnt[i][j]++;
                    } 
                    if(endd[index][0] == i - 1 && (endd[index][1] <= j - 1)) {
                        cnt[i][j]--;
                    }
                }
                if(j) {
                    cnt[i][j] = cnt[i][j - 1];
                    int index = s2[j - 1] - 'A'; //取走第一个序列第i个 （下标i-1
                    if(startt[index][1] == j - 1 && (startt[index][0] > i - 1 || startt[index][0] == -1)) {
                        cnt[i][j]++;
                    } 
                    if(endd[index][1] == j - 1 && (endd[index][0] <= i - 1)) {
                        cnt[i][j]--;
                    }
                }
                // cout << cnt[i][j] << ' ';
            }
            // cout << endl;
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i && j) {
                    dp[i][j] = min(dp[i - 1][j] + cnt[i - 1][j], dp[i][j - 1] + cnt[i][j - 1]);
                } 
                else if(i) {
                    dp[i][j] = dp[i - 1][j] + cnt[i - 1][j];
                }
                else if(j) {
                    dp[i][j] = dp[i][j - 1] + cnt[i][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}