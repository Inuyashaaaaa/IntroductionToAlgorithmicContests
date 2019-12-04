#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

LL solve(LL r, LL c, LL n, LL s, LL w, LL e) {
    if(n < s) swap(n, s);
    if(w < e) swap(w, e);

    LL ret = 0;
    
    //step1
    if(s) {
        ret += r * c;
        n -= s;
        r--;
        if(n) {
            ret += r * c * s * 2;
            n--;
        } else {
            ret += r * c * (s * 2 - 1);
        }
        s = 0;
    }

    if(e) {
        w -= e;
        if(w) {
            e *= 2;
            w--;
        } else {
            e = 2 * e - 1;
        }
        while(c * 1 - r * 1 + (c - 1) * e <= 0 && n) {
            ret += r * c;
            r--;
            n--;
        }
        ret += r * c;
        c--;
        ret += e * r * c;
        e = 0;
    }

    while(n + w > 0 && r * c > 0) {
        ret += r * c;
        if((c > r && w) || !n) {
            c--;
            w--;
        } else {
            n--;
            r--;
        }
    }
    return ret;

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL r, c;
    LL kase = 0;
    while(cin >> r >> c && r && c) {
        cout << "Case " << ++kase << ": ";
        LL n, s, w, e;
        cin >> n >> s >> w >> e;
        cout << max(solve(r, c, n, s, w, e), solve(c, r, w, e, n, s)) << endl;
    }
    return 0;
}