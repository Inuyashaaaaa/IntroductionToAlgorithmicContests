#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int w[maxn];
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, p, k;
        cin >> n >> p >> k;
        ms(a);
        for(int i = 0; i < n; i++) {
            cin >> w[i];
        }
        sort(w, w + n);
        int i;
        for(i = 0; i < n; i++) {
            a[i % k] += w[i];
            if(a[i % k] > p) {
                break;
            }
        }
        cout << i << endl;
 
    }
    return 0;
}