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
    int a;
    cin >> a;
    if(a % 2 == 0) {
        cout << 8 + a << " " << 8 << endl;
    }
    else {
        cout << 9 + a << " " << 9 << endl;
    }
    return 0;
}