#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i, j;
    cin >> n >> i >> j;
    //rows
    for(int x = 1; x <= n; x++) {
        cout << "(" << i << "," << x << ")";
    }
    cout << endl;

    //cols
    for(int y = 1; y <= n; y++) {
        cout << "(" << y << "," << j << ")";
    }
    cout << endl;

    //left
    int div = i - j;
    for(int x = 1; x <= n; x++) {
        if(x - div > 0 && x - div <= n) {
            cout << "(" << x << "," << x - div << ")";
        }
    }
    cout << endl;

    int sum = i + j;
    for(int x = n; x >= 1; x--) {
        if(sum - x > 0 && sum - x <= n) {
            cout << "(" << x << "," << sum - x << ")";
        }
    }
    cout << endl;


    return 0;
}