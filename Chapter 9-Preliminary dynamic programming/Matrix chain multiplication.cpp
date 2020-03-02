#include<iostream>
#include<algorithm>
#include<cstring>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X1fffffff
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];
int cols[maxn];
int rows[maxn];
int dp[maxn][maxn];

int matrix(int i, int j) {
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = INF;
    for(int k = i; k < j; k++) {
        ans = min(ans, matrix(i, k) +
        matrix(k + 1, j) + rows[i] * cols[k] * cols[j]);
    } 
    return ans;
}

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
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n - 1; i++) {
        rows[i] = a[i];
        cols[i] = a[i + 1];
        dp[i][i] = 0;
    }
    cout << matrix(0, n - 2) << endl;
    
    return 0;
}