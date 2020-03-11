#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
vector<LL> vec;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        vec.push_back(x);
    }
    if(n > m) {
        cout << 0 << endl;
        return 0;
    }
    LL ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans *= abs((vec[j] - vec[i]));
            ans %= m;
        }
    }
    cout << ans << endl;
    return 0;
}