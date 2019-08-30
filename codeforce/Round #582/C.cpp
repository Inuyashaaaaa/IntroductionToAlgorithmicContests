#include<bits/stdc++.h>
#define LL long long
using namespace std;

unordered_set<int> s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        s.clear();
        LL a, b;
        cin >> a >> b;
        LL n = 0;
        LL ret = 0;
        ret += b;
        LL circle = 0;     
        while(1) {
            if(s.count(ret % 10))
            break;
            circle += ret % 10;
            s.insert(ret % 10);
            ret += b;
            n++;
        }
        LL ans = a / (b * n) * circle;
        LL moddC = a % (b * n);
        moddC /= b;
       // cout << "*" << endl;
        ret = 0;
        ret += b;
        for(int i = 0; i < moddC; i++) {
            ans += ret % 10;
            ret += b;
        }

        cout << ans << endl;
    }
    return 0;
}