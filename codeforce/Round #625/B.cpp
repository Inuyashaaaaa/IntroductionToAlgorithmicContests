#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 6e5 + 10;
LL a[maxn];
LL offset[maxn];
LL cnt[maxn];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += n - i;
        offset[a[i]] += n - i;
        cnt[a[i]]++;
    }
    LL ans = 0;
    for(int i = 0; i < maxn; i++) {
        ans = max(ans, a[i] * cnt[a[i]] - offset[a[i]]);
    }
    cout << ans << endl;

    
    return 0;
}