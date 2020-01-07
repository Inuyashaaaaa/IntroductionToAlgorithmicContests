#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e3 + 10;
struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
    Point() {}
}p[maxn];

double dp[maxn][maxn];

double dist(int i, int j) {
    return hypot(p[i].x - p[j].x, p[i].y - p[j].y);
}

double DP(int i, int j) {
    if(dp[i][j]) return dp[i][j];
    return dp[i][j] = min(DP(i + 1, j) + dist(i, i + 1),
                DP(i + 1, i) + dist(j, i + 1));
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        ms(dp);
        for(int i = 1; i <= n; i++) 
        cin >> p[i].x >> p[i].y;
        for(int j = 1; j < n - 1; j++)
        dp[n - 1][j] = dist(n - 1, n) + dist(j, n);
        double ans = DP(2, 1) + dist(1, 2);
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}