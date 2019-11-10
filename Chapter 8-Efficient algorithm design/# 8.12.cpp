#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

LL f(int k, int i) {
    if(i == 0) return 0;
    if(k == 0) return 1;
    int w = 1 << (k - 1);
    if(w >= i) return 2 * f(k - 1, i);
    return f(k - 1, i - w) + 2 * pow(3, k - 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        int k, a, b;
        cin >> k >> a >> b;
        cout << "Case " << ++ kase << ": " << f(k, b) - f(k, a - 1) << endl;
    }
    
    return 0;
}