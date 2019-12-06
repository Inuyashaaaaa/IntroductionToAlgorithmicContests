#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

const int maxn = 4e5 + 10;

int num[maxn];
int cnt[maxn];

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
        int x;
        int lastx = -1;
        int count = -1;
        ms(cnt);
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x != lastx) num[++count] = x;
            lastx = x;
            cnt[count]++;
        }
        // for(int i = 0; i <= count; i++) {
        //     cout << num[i] << " " << cnt[i] << endl;
        // }
        // cout << endl;
        int num1 = 0;
        bool ok = true;
        int a[3];
        ms(a);
        a[0] = cnt[0];
        num1 += cnt[0];
        int maxd = cnt[0];
        int ans = 0;
        int d;
        for(d = 1; d <= count && num1 <= n / 2; d++) {
            ans += cnt[d];
            num1 += cnt[d];
            if(ans > maxd) {
                d++;
                break;
            }
        }
        a[1] = ans;
        ans = 0;
        for(; d <= count && num1 <= n / 2; d++) {
            ans += cnt[d];
            num1 += cnt[d];
        }
        a[2] = ans;
        d--;
        if(num1 > n / 2) {
            ans -= cnt[d];
            num1 -= cnt[d];
            a[2] -= cnt[d];
            if(ans <= maxd) a[2] = 0;
        }
        if(a[0] < a[1] && a[0] < a[2] && 
        a[0] + a[1] + a[2] <= n / 2) {
            cout << a[0] << " " << a[1] << " " << a[2] << endl;
        } else {
            cout << 0 << " " << 0 << " " << 0 << endl;
        }       
    }
    return 0;
}