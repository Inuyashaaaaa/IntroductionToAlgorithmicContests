#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];
int b[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int aWin = 0;
    int bWin = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] && !b[i]) {
            aWin++;
        }
        if(b[i] && !a[i]) {
            bWin++;
        }
    }
    cout << (aWin ? (bWin / aWin + 1) : -1) << endl;
    return 0;
}