#include<bits/stdc++.h>
#define LL long long
using namespace std;

//对于 100%的数据：1<=n<=100,000, 0<=w[i]<=10,000
const int maxn = 1e5 + 5;
int w[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        LL sum = w[i];
        for(int j = i - 1; j > 0; j--) {
            if(w[j] >= w[i]) sum += w[j];
            else break;
        }
        for(int j = i + 1; j <= n; j++) {
            if(w[j] >= w[i]) sum += w[j];
            else break;
        }
        sum *= w[i];
        ans = max(sum, ans);
    }
    cout << ans << endl;
    return 0;
}