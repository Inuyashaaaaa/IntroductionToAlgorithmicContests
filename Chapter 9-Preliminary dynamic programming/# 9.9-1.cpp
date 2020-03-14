#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int INF = 5e4 + 10;
const int maxn = 50 + 5;
int a[maxn];
int d[maxn][maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l;
    while(cin >> l && l) {
        int n;
        cin >> n;
        a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = l;
        for(int i = 0; i <= n + 1; i++) {
            for(int j = i; j <= n + 1; j++) {
                d[i][j] = INF;
            }
        }
        for(int i = 0; i <= n; i++) {
            d[i][i + 1] = 0;
        }
        for(int len = 2; len <= n + 1; len++) {
            for(int l = 0; l + len <= n + 1; l++) {
                int r = l + len;
                for(int m = l + 1; m < r; m++) {
                    d[l][r] = min(d[l][r], d[l][m] + d[m][r] + a[r] - a[l]);
                }
            }
        }
        cout << "The minimum cutting is ";
        cout << d[0][n + 1] << "." << endl;
    }
    return 0;
}