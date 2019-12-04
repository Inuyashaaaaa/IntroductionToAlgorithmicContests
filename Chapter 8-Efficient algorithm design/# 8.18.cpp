#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;
int c[maxn];    //ceiling
int f[maxn];    //floor
int h1[maxn];
int h2[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        int level = c[1];
        h1[1] = level;
        for(int i = 2; i <= n; i++) {
            if(c[i] < level) {
                level = c[i];
            } 
            if(f[i] > level) {
                level = f[i];
            }
            h1[i] = level;
        }
        level = c[n];
        h2[n] = level;
        for(int i = n - 1; i >= 1; i--) {
            if(c[i] < level) {
                level = c[i];
            }
            if(f[i] > level) {
                level = f[i];
            }
            h2[i] = level;
        }
        LL sum = 0;
        for(int i = 1; i <= n; i++) {
            int minn = min(h1[i], h2[i]);
            if(minn > f[i]) sum += minn - f[i];
        }
        cout << sum << endl;
    }
    return 0;
}