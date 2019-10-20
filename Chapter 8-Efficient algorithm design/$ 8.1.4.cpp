//O(n)
//最大连续和

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    int v = 0;
    int best = a[0]; 
    for(int i = 0; i < n; i++) {
        v += a[i];
        if(v > best) {
            best = v;
        }
        //如果前面的部分是v < 0 的加上就更小了，所以不要
        if(v < 0) v = 0;
    }
    cout << best << endl;
    return 0;
}