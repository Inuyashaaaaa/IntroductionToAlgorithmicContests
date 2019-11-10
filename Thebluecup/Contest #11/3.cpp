#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], b[maxn], c[maxn];
int d[maxn], e[maxn], f[maxn];
int t[maxn];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x1, y1, z1, x2, y2, z2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> 
        d[i] >> e[i] >> f[i] >> t[i];
    }
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    for(int i = 0; i < n; i++) {
        x1 += a[i] * t[i];
        y1 += b[i] * t[i];
        z1 += c[i] * t[i];
        x2 += d[i] * t[i];
        y2 += e[i] * t[i];
        z2 += f[i] * t[i];
    }
    double ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) *
    (y1 - y2) + (z1 - z2) * (z1 - z2));
    cout << fixed << setprecision(4) << ans << endl;

    return 0;
}