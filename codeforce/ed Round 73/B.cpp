#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i % 2 == 0) cout << 'B';
            else if(j % 2 == 0) cout << 'W';
            else cout << 'B';
        }
        cout << endl;
    }
    return 0;
}