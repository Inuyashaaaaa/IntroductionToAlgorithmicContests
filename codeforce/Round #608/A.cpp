#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    LL ans = 0;
    if(f > e) {
        LL minn = min(min(b, c), d);
        ans = minn * f;
        d -= minn;
        minn = min(a, d);
        ans += minn * e; 
    } else {
        LL minn = min(a, d);
        ans = minn * e;
        d -= minn;
        minn = min(min(b, c), d);
        ans += minn * f; 
    }
    cout << ans << endl;
    return 0;
}