#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e6 + 10;
LL a[maxn];
LL sum[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) sum[i] = sum[i - 1] + a[i];
        else sum[i] = a[i];
    }
    a[n] = 0;
    int i = 0;
    LL ans = 0;
    stack<LL> s;
    while(i <= n) {
        if(s.empty() || a[s.top()] <= a[i]) {
            s.push(i++);
        } else {
            LL t = s.top();
            s.pop();
            LL e;
            if(s.empty()) {
                e = sum[i - 1] * a[t];
            }
            else {
                e = (sum[i - 1] - sum[s.top()]) * a[t];
            }
            if(e > ans) {
                ans = e;
            }
        }
    }
    cout << ans << endl;
    return 0;
}