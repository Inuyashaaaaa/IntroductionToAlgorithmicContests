#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int q, x;
        cin >> q >> x;
        int maxn = -1;
        int maxd = 0;
        while(q--) {
            int a, b;
            cin >> a >> b;
            maxn = max(a, maxn);
            maxd = max(maxd, a - b);
        }
        if(x <= maxn) {
            cout << "1" << endl;
            continue;
        }
        if(maxd == 0) {
            cout << "-1" << endl;
            continue;
        }
        int cnt = 0;
        x-= maxn;
        if(x % maxd == 0)
        {
            x/= maxd;
        } else {
            x/= maxd;
            x++;
        }      
        x++;
        cout << x << endl;
    }
    return 0;
}