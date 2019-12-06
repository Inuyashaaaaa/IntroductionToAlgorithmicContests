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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e1 = b - a;
    int e2 = c - d;
    if(e1 == -1 && c == 0 && d == 0) {
        cout << "YES" << endl;
        cout << 0 << " ";
        for(int i = 0; i < b; i++) {
            cout << "1 0 ";
        }
        return 0;
    }
    if(e2 == -1 && a == 0 && b == 0) {
        cout << "YES" << endl;
        cout << 3 << " ";
        for(int i = 0; i < c; i++) {
            cout << "2 3 ";
        }
        return 0;
    }
    if(e1 < 0 || e2 < 0 || abs(e1 - e2) > 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(e1 > e2) {
        cout << 1 << " ";  
    }
    for(int i = 0; i < a; i++) {
        cout << "0 1 ";
    }
    for(int i = 0; i < min(e1, e2); i++) {
        cout << "2 1 ";
    }
    for(int i = 0; i < d; i++) {
        cout << "2 3 ";
    }
    if(e2 > e1) {
        cout << 2 << " ";
    }
    cout << endl;
    return 0;
}