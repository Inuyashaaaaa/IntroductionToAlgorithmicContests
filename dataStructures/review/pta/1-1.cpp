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
    int b = 1;
    int ans = 0;
    bool first = true;
    while(cin >> a && a) {
        if(a == 1) {
            b = 1;
            first = true;
        }
        if(a == 2) {
            if(first) b = 2;
            else b += 2;
            first = false;
        }     
        ans += b;
    }  
    cout << ans << endl;
    return 0;
}