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
    int T;
    cin >> T;
    while(T--) {
        LL a, b;
        LL c = 9;
        LL ans = 0;
        cin >> a >> b;
        while(b >= c) {
            ans++;
            c *= 10;
            c += 9;
        }
        cout << ans * a << endl;
    }
    return 0;
}