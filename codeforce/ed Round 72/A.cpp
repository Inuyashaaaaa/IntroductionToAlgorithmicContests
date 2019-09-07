#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL T;
    cin >> T;
    int cnt = 1;
    while(T--) {
        LL a, b, c;
        cin >> a >> b >> c;
        a += c;
        a ++;
        //cout << a  << ":" << b << endl;
        LL d = (a - b) / 2;
        d = min(d, c + 1);
        cout << (d > 0 ? d : 0) << endl;
        cnt++;
    }
    return 0;
}
