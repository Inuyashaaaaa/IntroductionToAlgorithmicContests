#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 11;
int n, m;
bool exi[maxn][maxn];
bool vis[4][maxn * 2];
bool occupy[maxn][maxn];

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!exi[i][j]) continue;
            if(!vis[0][i] && !vis[1][j] && !vis[2][i + j] && !vis[3][maxn + i - j])
            return false;
        }
    }
    return true;
}

bool dfs(int d, int maxd) {
    if(d == maxd) {
        return check();
    }
    for(int i = 0; i < n; i++) {
        int t0, t1, t2, t3;
        for(int j = 0; j < m; j++) {    
            if(occupy[i][j]) continue;
            t0 = vis[0][i];
            t1 = vis[1][j];
            t2 = vis[2][i + j];
            t3 = vis[3][maxn + i - j];
            occupy[i][j] = 1;
            vis[0][i] = 1;
            vis[1][j] = 1;
            vis[2][i + j] = 1;
            vis[3][maxn + i - j] = 1;
            if(dfs(d + 1, maxd)) return true;
            occupy[i][j] = 0;
            vis[0][i] = t0;
            vis[1][j] = t1;
            vis[2][i + j] = t2;
            vis[3][maxn + i - j] = t3;        
        }
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> n && n && cin >> m) {
        cout << "Case " << ++kase << ": ";
        memset(exi, 0, sizeof(exi));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                if(ch == 'X')
                exi[i][j] = true;
            }
        }

        if(check()) {
            cout << 1 << endl;
            continue;
        }
        int maxd;
        for(maxd = 0; ; maxd++) {
            memset(occupy, 0, sizeof(occupy));
            memset(vis, 0, sizeof(vis));
            if(dfs(0, maxd)) break;
        }
        cout << maxd << endl;
    }
    return 0;
}