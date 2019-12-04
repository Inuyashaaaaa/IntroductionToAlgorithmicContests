#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e2 + 10;

int D[maxn][maxn];
int vis[maxn];
int topo[maxn];
int t;

bool dfs(int u) {
    vis[u] = -1;
    for(int i = 0; i < 5; i++) {  
        if(D[u][i]) {
            if(vis[i] == -1) return false;
            else if(!vis[i] && !dfs(i)) return false; //成环
        }
    }
    //访问完毕
    vis[u] = 1;
    topo[t--] = u;
    return true;
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M; //N 球队 M 比赛
    cin >> N >> M;
    ms(D);
    ms(vis);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        D[a][b] = 1;
    }
    t = N;
    for(int i = N; i >= 1; i--) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= N; i++) {
        if(i != 1) cout << " ";
        cout << topo[i];
    }

    return 0;
}