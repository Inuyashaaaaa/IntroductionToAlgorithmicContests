#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 3000;
int a[maxn];



int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) {
            LL x;
            cin >> x;
            if(x > 2048) continue;
            a[x]++;
        }
        for(int i = 0; i < 11; i++) {
            int e1 = pow(2, i);
            int e2 = pow(2, i + 1);
            //cout << e1 << " " << e2 << endl;
            a[e2] += a[e1] / 2;
        }
        if(a[2048]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl; 
        }
    }
    
    return 0;
}