#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], b[maxn];

bool cmp(int& a, int& b) {
    return a > b;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
         for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n, cmp);
        LL ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i] * b[i];
        }
        cout << ans << endl;
    }

    
    return 0;
}