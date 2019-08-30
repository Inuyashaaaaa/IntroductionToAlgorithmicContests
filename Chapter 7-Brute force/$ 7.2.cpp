#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int kase = 0;
    while(cin >> n) {
        LL a[20];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        LL ans = 0;
        for(int i = 0 ; i < n ; i++) {
            LL ret = a[i];
            ans = max(ans, ret);
            for(int j = i + 1; j < n; j++) {
                ret *= a[j];
                ans = max(ans, ret);
            }
        }
        cout << "Case #" << ++kase << ": The maximum product is " << ans << "." << endl;
        cout << endl;
    }
    return 0;
}