#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

map<int, int> mm;

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
            cin >> a[i];
            mm[a[i]] = i;
        }
        int left = maxn;
        int right = -1;
        for(int i = 1; i <= n; i++) {
            int pos = mm[i];
            if(pos < left) {
                left = pos;
            }
            if(pos > right) {
                right = pos;
            }
            if(right - left + 1 == i) cout << 1;
            else cout << 0;
        }
        cout << endl;

    }
    return 0;
}