#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    LL ans = (pow(n, n + 1)) - ((n - 1) * m);
    cout << ans << endl; 
    return 0;
}