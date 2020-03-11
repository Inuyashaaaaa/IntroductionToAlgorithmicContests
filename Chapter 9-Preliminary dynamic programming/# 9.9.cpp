#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 50 + 5;
int l, n;

int a[maxn];
int edge[maxn][maxn];

void init() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            if(abs(i - j) <= 1) edge[i][j] = 0;
            else edge[i][j] = 1e7;
        }
    }
}

int solve(int l, int r) {
    // if(l + 1 >= r) return 0;
    if(edge[l][r] != 1e7) return edge[l][r];
    for(int i = l + 1; i < r; i++) {
        edge[l][r] = min(edge[l][r], solve(l, i) + solve(i, r)  + a[r] - a[l]);
    }
    // cout << "l: " << l << " r: " << r << " " << edge[l][r] << endl;
    return edge[l][r];
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> l && l) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        a[n + 1] = l; 
        init();
        cout << "The minimum cutting is " 
        << solve(0, n + 1) << "." << endl;
    }
    return 0;
}