#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e3 + 10;
int a[maxn][maxn];
int n;
int vis[maxn][maxn];
int d[maxn][maxn];

// O(2^n)
int solve1(int i, int j) {
    if(i == n + 1) return 0;
    return a[i][j] = a[i][j] + max(solve1(i + 1, j), solve1(i + 1, j + 1));
}

// O(n^2) 记忆化搜索方式
int solve2(int i, int j) {
    if(i == n + 1) return 0;
    if(vis[i][j] > 0) return vis[i][j];
    return vis[i][j] = a[i][j] + max(solve2(i + 1, j), solve2(i + 1, j + 1));
}

// O(n^2) 递推
void solve3() {
    ms(d);
    for(int i = 1; i <= n; i++) {
        d[n][i] = a[n][i];
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
        }
    }
    cout << d[1][1] << endl;
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j]; 
        }
    }

    //solve1
    // cout << solve1(1, 1) << endl;

    //solve2
    // memset(vis, -1, sizeof(vis));
    // cout << solve2(1, 1) << endl;

    //solve3
    solve3();
    return 0;
}