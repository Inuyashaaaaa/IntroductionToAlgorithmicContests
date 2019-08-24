#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 20;
bool edge[maxn][maxn];
int c[maxn];
int ans[maxn];
int n, m;
int t;

bool dfs(int i) {
    c[i] = -1; 
    for(int j = 1; j <= n; j++) {
        if(edge[i][j]) {
            if(c[j] == -1) return false;        
            if(!c[j] && !dfs(j)) return false;  
        }
    }
    c[i] = 1; 
    ans[t--] = i;
    return true;
}

bool topoSort() {
    for(int i = 1; i <= n; i++) {
        if(!c[i]) 
            if(!dfs(i))
                return false;
    }
    return true;
}

int main() {
    while(cin >> n >> m && n) {
        memset(c, 0, sizeof(c));
        memset(edge, false, sizeof(edge));
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            edge[a][b] = true;
        }
        t = n;
        topoSort();
        for(int i = 1;i <= n; i++) {
            if(i == 1)
            cout << ans[i];
            else
            cout << " " << ans[i];
        }
        cout << endl;
    }
}