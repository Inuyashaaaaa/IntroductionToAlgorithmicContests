#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e3 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        for(int i = 1; i <= n; i++) {
            int index1 = -10;
            int index2 = -10;
            for(int j = 0; j < n; j++) {
                if(a[j] == i) {
                    index1 = j;
                    break;
                }
            }
            for(int j = n - 1; j >= 0; j--) {
                if(a[j] == i) {
                    index2 = j;
                    break;
                }
            }
            if(index1 == -10) continue;
            if(index1 + 1 == index2
            || index1 == index2) continue;
            flag = true;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}