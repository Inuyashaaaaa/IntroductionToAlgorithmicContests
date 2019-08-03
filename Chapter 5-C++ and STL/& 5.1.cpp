#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10000;

int main() {
    int n, q, x, a[maxn], kase = 0;
    ios::sync_with_stdio(false);
    while(cin >> n >> q && n) {      
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << "CASE# " << ++kase << ":" << endl;
        while(q--) {
            cin >> x;
            int  p = lower_bound(a, a+n, x) - a;
            if(a[p] == x) cout << x << " found at " << p + 1 << endl;
            else cout << x << " not found" << endl;
        }
    }
    // system("pause");
    return 0;
}