#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e4 + 10;

// O(n^2)

int n;
int dp[maxn];
int a[maxn];
int prevv[maxn];

void print(int index) {
    if(index == 0) return;
    print(prevv[index]);
    cout << a[index] << " ";
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] > a[i] && dp[j] < dp[i] + 1) {
                dp[j] = dp[i] + 1;
                prevv[j] = i;
            }
        }
    }
    int ans = 0;
    int index = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            index = i;
        }
    }
    print(index);
    cout << endl;
    cout << ans << endl;
    return 0;
}