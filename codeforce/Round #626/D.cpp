#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 4e5 + 10;
LL a[maxn];
LL b[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    for(int k = 0; k < 25; k++) {
        for(int i = 0; i < n; i++) {
            b[i] = a[i] & ((1 << (k + 1)) - 1);
        }
        sort(b, b + n);
        int d = (1 << k);
        LL cnt = 0;
        for(int i = n - 1, x = 0, y = 0, z = 0; i >= 0; i--) {
            while(x < n && b[i] + b[x] < d) 
                x++;
            while(y < n && b[i] + b[y] < 2 * d)
                y++;
            while(z < n && b[i] + b[z] < 3 * d)
                z++;
            cnt += min(y, i) - min(x, i);
            cnt += i - min(z, i);
        }
        if(cnt & 1) {
            ans |= d;
        }
    }
    cout << ans << endl;

    return 0;
}