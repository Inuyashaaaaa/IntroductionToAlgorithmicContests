#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b, c;
    while(m--) {
        cin >> b >> c;
        swap(a[b - 1], a[c - 1]);
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}