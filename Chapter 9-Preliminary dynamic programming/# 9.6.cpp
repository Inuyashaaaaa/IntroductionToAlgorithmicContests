#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X3fffffff
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];
int s[maxn];

struct lamp {
    int v, k, c, l;
    friend bool operator < (const lamp& l1, const lamp& l2) {
        return l1.v < l2.v;
    }
}l[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        s[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> l[i].v >> l[i].k >> l[i].c >> l[i].l;
        }
        sort(l + 1, l + 1 + n);
        for(int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + l[i].l;
            dp[i] = s[i] * l[i].c + l[i].k;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * l[i].c + l[i].k);
                // cout << ">> i: " << i << " j: " << j << " :" << dp[i] << endl; 
            }
        }
        cout << dp[n] << endl;

    }
    return 0;
}