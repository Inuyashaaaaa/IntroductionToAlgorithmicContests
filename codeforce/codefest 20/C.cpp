#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 +10;
LL a[maxn];
LL b[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int a1 = 0;
    int b1 = 0;
    while(a1 + b1 <= n + m - 2) {
        if(a[a1] % p == 0) {
            a1++;
            continue;
        }
        if(b[b1] % p == 0) {
            b1++;
            continue;
        }
        cout << a1 + b1 << endl;
        return 0;
    }
    return 0;
}