#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int kase = 0;
    while(cin >> n) {
        cout << 2 << " " << n << " " << n << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << s[i];
            }
            cout << endl;
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                cout << s[i];
            }
             cout << endl;
        }
    }

    return 0;
}