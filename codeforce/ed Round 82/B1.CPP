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
        LL n, g, b;
        cin >> n >> g >> b;
        LL temp = n;
        if(n % 2) {
            n /= 2;
            n++;
        }
        else {
            n /= 2;
        }
        LL num = n / g;
        LL ans = 0;
        if(n % g == 0) {
            ans = (num - 1) * (g + b) + g;
        }
        else {
            ans = num * (g + b) + n % g;
        }
        if(ans < temp) {
            cout << temp << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}