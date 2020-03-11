#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const LL maxn = 4e4 + 10;
LL a[maxn], b[maxn];
LL aa[maxn], bb[maxn];
LL aaa[maxn], bbb[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;
    for(LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(LL i = 0; i < m; i++) {
        cin >> b[i];
    }
    LL cnt = 0;
    for(LL i = 0; i < n; i++) {
        if(a[i] == 1) {
            cnt++;
        }
        if(a[i] == 0) {
            aa[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) {
        aa[cnt]++;
        cnt = 0;
    }
    for(LL i = 0; i < m; i++) {
        if(b[i] == 1) {
            cnt++;
        }
        if(b[i] == 0) {
            bb[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) {
        bb[cnt]++;
        cnt = 0;
    }

    LL duan = 0;
    for(LL i = n; i >= 1; i--) {
        duan += aa[i];
        aaa[i] = aaa[i + 1] + duan;
    }
    duan = 0;
    for(LL i = m; i >= 1; i--) {
        duan += bb[i];
        bbb[i] = bbb[i + 1] + duan;
    }
    LL ans = 0;
    for(LL i = 1; i <= sqrt(k); i++) {
        if(k % i == 0) {
            LL val = k / i;
            if(val >= maxn) continue;
            ans += aaa[i] * bbb[val];
            if(i != val)
                ans += aaa[val] * bbb[i];
        }
    }
    cout << ans << endl;
    return 0; 
}