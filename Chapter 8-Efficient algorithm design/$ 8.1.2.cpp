//O(n^2)
//最大连续和

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int sum[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    //保留前缀和
    ms(sum);
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int best = a[1];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int s = 0;
            s = sum[j] - sum[i - 1];
            if(s > best) {
                best = s;
            }
        }
    }
    cout << best << endl;
    return 0;
}