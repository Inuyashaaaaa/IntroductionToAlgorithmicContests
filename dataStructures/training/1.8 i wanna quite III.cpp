#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 3e6 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int e = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        e ^= a[i];
    }
    int index;
    for(index = 0; index < n; index++) {
        if(((e >> index) & 1) == 1) {
            break;
        }
    }

    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++) {
        if(((a[i] >> index) & 1) == 1) {
            ans1 ^= a[i];
        } else {
            ans2 ^= a[i];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << " " << ans2 << endl;

    return 0;
}