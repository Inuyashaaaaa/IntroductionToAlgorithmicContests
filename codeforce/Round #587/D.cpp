#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int b[maxn];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int maxn = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    for(int i = 0; i < n; i++) {
        b[i] = maxn - a[i];
    }
    int g = b[0];
    for(int i = 1; i < n; i++) {
        if(b[i]) {
            g = __gcd(g, b[i]);
        }
    }
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        if(b[i])
        ans += b[i] / g; 
    }
    cout << ans <<  " " << g << endl;
    return 0;
}