#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    if(r == c && r == 1) {
        cout << 0 << endl;
        return 0;
    }
    if(r == 1) {
        for(int i = 0; i < c; i++) {
            cout << i + 2 << " ";
        }
        cout << endl;
        return 0;
    }
    if(c == 1) {
        for(int i = 0; i < r; i++) {
            cout << i + 2 << endl;
        }
        return 0;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << (c + i) * j << " ";
        }
        cout << endl;
    }
    return 0;
}