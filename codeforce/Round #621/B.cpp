#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
#define INF 0x1fffffff
const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int choice1 = INF;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == 0) continue;
            if(x % a[i] == 0) {
                choice1 = x / a[i];
                break;
            }
        }
        int choice2 = a[n - 1] > x ? 2 : x / a[n - 1] + 1;
        cout << min(choice2, choice1) << endl;
    }
    return 0;
}