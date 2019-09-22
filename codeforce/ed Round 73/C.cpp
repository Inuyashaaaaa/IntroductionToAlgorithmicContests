#include<bits/stdc++.h>
#define LL long long
#define INF 0x7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int ans = 0;
    while(T--) {
        ans = 0;
        int c, m, n;
        cin >> c >> m >> n;
        int minn = c;
        minn = min(m, minn);
        minn = min(n, minn);
        ans += minn;
        c -= minn;
        m -= minn;
        minn = (c + m) / 3;
        minn = min(c, minn);
        minn = min(m, minn);
        ans += minn;
        cout << ans << endl;
    }
    return 0;
}