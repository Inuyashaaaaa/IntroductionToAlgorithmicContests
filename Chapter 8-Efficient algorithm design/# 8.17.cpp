#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1024 + 10;
char G[maxn][maxn];
int vis[maxn], haveFailed[maxn];
int n;

void dfs(int m) {
    if(m == 1) return;
    ms(vis);
    //step 1
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            // 1 < i && j > i && 1 > j
            if(vis[i] || vis[j] || haveFailed[i] || haveFailed[j]) continue;
            if(!G[1][i] && G[j][i] && G[1][j]) {
                cout << i << " " << j << endl;
                vis[i] = vis[j] = 1;
                haveFailed[i] = 1;
                break;
            }
        }
    }
    //step 2
    for(int i = 2; i <= n; i++) {
        if(vis[i] || haveFailed[i]) continue;
        if(G[1][i]) {
            cout << 1 << " " << i << endl;
            vis[i] = true;
            haveFailed[i] = true;
            break;
        }
    }

    //step3
    bool flag = false;
    int pre, cur;
    for(int i = 2; i <= n; i++) {
        if(!G[1][i] && !vis[i] && !haveFailed[i]) {
            if(!flag) {
                flag = true;
                pre = i;
            } else {
                flag = false;
                cur = i;
                if(G[pre][cur]) haveFailed[cur] = true;
                else haveFailed[pre] = true;
                vis[pre] = vis[cur] = 1;
                cout << pre << " " << cur << endl;
            }
        }
    }

   //step4
    flag = false;
    for(int i = 2; i <= n; i++) {
        if(!vis[i] && !haveFailed[i]) {
            if(!flag) {
                flag = true;
                pre = i;
            } else {
                flag = false;
                cur = i;
                if(G[pre][cur]) haveFailed[cur] = true;
                else haveFailed[pre] = true;
                vis[pre] = vis[cur] = 1;
                cout << pre << " " << cur << endl;
            }
        }
    }
 
    dfs(m >> 1);
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> G[i][j];
                G[i][j] -= '0';
            }
        }
        ms(haveFailed);
        dfs(n);
    }
    return 0;
}