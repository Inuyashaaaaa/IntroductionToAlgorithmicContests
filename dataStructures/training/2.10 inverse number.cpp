#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 5e2 + 10;
bool vis[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ms(vis);
    for(int i = 0; i < n ;i++) {
        int x;
        cin >> x;
        int cnt = 0;
        int j;
        vis[0] = true;
        for(j = 0; j <= n; j++) {
            if(!vis[j]) {
                cnt++;
            }
            if(cnt == x) {
                while(vis[++j]);
                vis[j] = true;
                break;
            }
        }
        if(i) cout << " ";
        cout << j;
    }
    return 0;
}