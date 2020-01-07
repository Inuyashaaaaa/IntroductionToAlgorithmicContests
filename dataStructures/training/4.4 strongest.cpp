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
    int n, x;
    cin >> n;
    stack<int> s;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        cin >> x;
        while(!s.empty() && s.top() <= x) {
            s.pop();
        }
        if(s.empty()) {
            ans = max(ans, x); 
        } else {
            ans = max(ans, s.top() + x);
        }
        s.push(x);
    }
    cout << ans << endl;
    return 0;
}