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
        LL ans = 0;
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        int ar = c - r;
        int br = c + r;
        // 1
        if(c <= a) {
            if(br <= a) {
                cout << b - a << endl;
            }
            else if(br >= b) {
                cout << 0 << endl;
            }
            else {
                cout << b - a - (br - a) << endl;
            }
        }
        //2
        else if(c >= b) {
            if(ar >= b) {
                cout << b - a << endl;
            }
            else if(ar <= a) {
                cout << 0 << endl;
            }
            else {
                cout << b - a - (b - ar) << endl;
            }
        }
        else {
            int ans = 0;
            if(ar >= a) {
                ans += ar - a;
            }
            if(br <= b) {
                ans += b - br;
            }
            cout << ans <<endl;
        }

    }
    return 0;
}