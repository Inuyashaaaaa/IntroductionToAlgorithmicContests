#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e6 + 10;
bool vis[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> s;
    string ss;
    cin >> ss;
    for(int i = 0; i < ss.size(); i++) {
        if(ss[i] == '(') {
            s.push(i);
        }
        if(ss[i] == ')') {
            if(!s.empty()) {
                vis[s.top()] = 1;
                vis[i] = 1;
                s.pop();
            }
        }
    }
    int ans = 0;
    int maxn = 0;
    vis[ss.size() == 0];
    int cnt = 0;
    for(int i = 0; i <= ss.size(); i++) {
        if(vis[i]) ans++;
        if(!vis[i]) {
            if(ans > maxn) {
                maxn = ans;
                cnt = 0;
            }
            if(ans == maxn) {
                cnt++;
            }
            ans = 0;
        }
    }
    cout << maxn << endl << cnt << endl;
    return 0;
}