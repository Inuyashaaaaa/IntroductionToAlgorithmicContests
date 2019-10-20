#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 15 + 5;
int n;
int G[maxn][maxn];
int vis[maxn];
int line;

bool two(int s) {
    for(int i = 0; i < n; i++) {
        if((s >> i) & 1) continue; //该节点已被打开 等待插环
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if((s >> j) & 1) continue;
            if(G[i][j]) cnt++;
        }
        if(cnt > 2) return true;
    }
    return false;
}

bool dfs(int now, int s, int fa) {
    vis[now] = -1; //正在访问
    for(int i = 0; i < n; i++) {
        if(((s >> i) & 1) || !G[now][i] || i == fa) continue; //无视断开的点
        if(vis[i]) return true;    //又走回来了
        if(dfs(i, s, now)) return true;
    }
    vis[now] = 1; //访问完毕
    return false;
}

bool circle(int s) {
    line = 0; //残留的链数
    for(int i = 0; i < n; i++) {
        if((s >> i) & 1) continue;
        if(vis[i]) continue;
        if(dfs(i, s, -1)) 
            return true;
        line++;
    }
    return false;
}

int cal(int s) {
    return s == 0 ? 0 : cal(s / 2) + (s & 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> n && n) {
        memset(G, 0, sizeof(G));
        int a, b;
        while(cin >> a >> b && a != -1) {
            G[a - 1][b - 1] = G[b - 1][a - 1] = 1;
        }
        int s = (1 << n);
        //二进制枚举哪些节点需要打开
        int ans = maxn;
        for(int i = 0; i < s; i++) {
            memset(vis, 0, sizeof(vis));
            if(two(i)) continue;
            if(circle(i)) continue;
            //节点数小于链数的话，连不起来
            if(cal(i) >= line - 1) {
                ans = min(ans, cal(i));
            }
        }
        //Set 1: Minimum links to open is 6
        cout << "Set " << ++ kase << ": Minimum links to open is " << ans << endl;
    }   
    return 0;
}
