#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;

//前面的neg 和 pos
int m1[maxn];
int m2[maxn];

//统计前缀和
int m[maxn];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int r = 1;
    LL ans1 = 0;
    LL ans2 = 0;
    for(int i = 1; i <= n; i++) {
        m1[i] = ans1;
        m2[i] = ans2;
        int x;
        cin >> x;
        if(x < 0) {
            r *= -1;
        }
        m[i] = r;
        if(m[i] < 0) ans1 ++;
        else ans2 ++;
    }
    for(int i = 2; i <= n ;i++) {
        if(m[i] == 1) {
            ans1 += m1[i];
            ans2 += m2[i];
        } else {
            ans1 += m2[i];
            ans2 += m1[i];
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}