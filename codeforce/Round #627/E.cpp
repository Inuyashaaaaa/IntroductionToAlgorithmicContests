#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int INF = 2000 + 10;
const int maxr = 2e3 + 10;
int dp[maxr][maxr];
int a[maxr];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    for(int i = 0; i < maxr; i++) {
        for(int j = 0; j < maxr; j++)
            dp[i][j] = -1;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0] >= l && a[0] <= r) {
        dp[0][a[0]] = 1;
    }
    else {
        dp[0][a[0]] = 0;
    }
    if(a[0] - 1 >= l && a[0] - 1 <= r) {
        dp[0][a[0] - 1] = 1;
    }
    else {
        dp[0][a[0] - 1] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < h; j++) {
            if(dp[i - 1][j] == -1) continue;
            if((a[i] + j) % h >= l && (a[i] + j) % h <= r
            ) {
                dp[i][(a[i] + j) % h] = max(dp[i - 1][j] + 1, dp[i][(a[i] + j) % h]);
            }
            else {
                dp[i][(a[i] + j) % h] = max(dp[i - 1][j], dp[i][(a[i] + j) % h]);
            }
            if((a[i] - 1 + j) % h >= l && (a[i] - 1 + j) % h <= r) {
                dp[i][(a[i] - 1 + j) % h] = max(dp[i - 1][j] + 1, dp[i][(a[i] - 1 + j) % h]);
            }
            else {
                dp[i][(a[i] - 1 + j) % h] = max(dp[i - 1][j], dp[i][(a[i] - 1 + j) % h]);
            }
        }
    }
    cout << *std::max_element(dp[n - 1], dp[n - 1] + h) << endl;
    return 0;
}