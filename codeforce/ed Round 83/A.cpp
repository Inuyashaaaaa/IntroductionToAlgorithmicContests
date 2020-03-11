#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        bool flag = true;
        int p = 1;
        while(1) {
            if(m * p == n) {
                flag = false;
                cout << "YES" << endl;
                break;
            }
            if(m * p > n) {
                break;
            }
            p++;
        }
        if(flag) cout << "NO" << endl;
    }
    return 0;
}