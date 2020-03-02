#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

const int maxn = 5e3 + 10;

int dp[maxn][maxn];
int cnt[maxn][maxn];
int _start[26][2]; // 26个元素在第一个地方出现
int _end[26][2]; // 26个元素在最后一个地方出现


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        memset(_start, -1, sizeof(_start));
        memset(_end, -1, sizeof(_end));
        ms(cnt);
        for(int i = 0; i < n; i++) {
            int index  = s1[i] - 'A';
            if(_start[index][0] == -1) {
                _start[index][0] = i;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int index = s1[i] - 'A';
            if(_end[index][0] == -1) {
                _end[index][0] = i;
            }
        }
        for(int i = 0; i < m; i++) {
            int index = s2[i] - 'A';
            if(_start[index][1] == -1) {
                _start[index][1] = i;
            }
        }
        for(int i = m - 1; i >= 0; i--) {
            int index = s2[i] - 'A';
            if(_end[index][1] == -1) {
                _end[index][1] = i;
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = 10001;
            }
        }
        dp[0][0] = 0;
        cnt[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 && j == 0) continue;
                if(i == 0) {
                    dp[i][j] = dp[i][j - 1] + cnt[i][j - 1];
                    int index = s2[j - 1] - 'A';
                    if(j - 1 == _start[index][1] && (i - 1 < _start[index][0] || _start[index][0] == -1)) {
                        cnt[i][j] = cnt[i][j - 1] + 1;
                    }
                    if(j - 1 == _end[index][1] && (i - 1 >= _end[index][0])) {
                        cnt[i][j] = cnt[i][j - 1] - 1;
                    }
                    continue;
                }
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j] + cnt[i - 1][j];
                    int index = s1[i - 1] - 'A';
                    if(i - 1 == _start[index][0] && (j - 1 < _start[index][1] || _start[index][1] == -1)) {
                        cnt[i][j] = cnt[i - 1][j] + 1;
                    }
                    if(i - 1 == _end[index][0] && (j - 1 >= _end[index][1])) {
                        cnt[i][j] = cnt[i - 1][j] - 1;
                    }
                    continue;
                }
                int num1 = dp[i][j - 1] + cnt[i][j - 1];
                int num2 = dp[i - 1][j] + cnt[i - 1][j];
                if(num1 < num2) {     
                    dp[i][j] = num1;
                    int index = s2[j - 1] - 'A';
                    if(j - 1 == _start[index][1] && (i - 1 < _start[index][0] || _start[index][0] == -1)) {
                        cnt[i][j] = cnt[i][j - 1] + 1;
                    }
                    if(j - 1 == _end[index][1] && (i - 1 >= _end[index][0])) {
                        cnt[i][j] = cnt[i][j - 1] - 1;
                    }                  
                    continue;
                }
                if(num1 >= num2) {                
                    dp[i][j] = num2;
                    int index = s1[i - 1] - 'A';
                    if(i - 1 == _start[index][0] && (j - 1 < _start[index][1] || _start[index][1] == -1)) {
                        cnt[i][j] = cnt[i - 1][j] + 1;
                    }
                    if(i - 1 == _end[index][0] && (j - 1 >= _end[index][1])) {
                        cnt[i][j] = cnt[i - 1][j] - 1;
                    }                 
                    continue;
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}