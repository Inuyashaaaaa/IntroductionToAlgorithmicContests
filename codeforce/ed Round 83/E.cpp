#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e2 + 10;
int a[maxn];
int dp[maxn];
int d[maxn][maxn];

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      d[i][j] = -1;
    }
  }
  for(int i = 0; i < n; i++) {
    d[i][i + 1] = a[i];
  }
  for(int len = 2; len <= n; len++) {
    for(int l = 0; l + len <= n; l++) {
      int r = l + len;
      for(int m = l + 1; m < r; m++) {
        if(d[l][m] != -1 && d[l][m] == d[m][r]) {
          d[l][r] = d[l][m] + 1;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    dp[i] = i;
    for(int j = 0; j < i; j++) {
      if(d[j][i] != -1) {
        dp[i] = min(dp[i], dp[j] + 1);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}