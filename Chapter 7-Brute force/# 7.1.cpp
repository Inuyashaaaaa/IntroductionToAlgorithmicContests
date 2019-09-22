#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 20 + 5;

int p[maxn];
void init() {
    for(int i = 1; i < maxn; i++) {
        p[i] = i;
    }
}

int find(int a) {
    while(a != p[a]) {
        a = p[a];
    }
    return a;
}

void merge(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot != bRoot)
    p[aRoot] = bRoot;
}

int G[maxn][maxn];
bool vis[maxn];
int aa[maxn];
int n;
int cnt = 0;

void dfs(int u, int d) {
    if(u == n) {
        cnt++;
        for(int i = 0; i < d; i++) {
            if(i) cout << " ";
            cout << aa[i];
        }
        cout << endl;
        return;
    }
    for(int i = 1; i < maxn; i++) {
        if(!vis[i] && G[u][i]) {
            vis[i] = true;
            aa[d] = i;
            dfs(i, d + 1);
            vis[i] = false;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> n) {
        init();
        cout << "CASE " << ++kase << ":" << endl;
        int a, b;
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        while(cin >> a >> b && a && b) {
            G[a][b] = 1;
            G[b][a] = 1;
            merge(a, b);
        }
        int root = p[n];
        if(find(1) != find(n)) {
            cout << "There are " << 0 << " routes from the " << 
            "firestation to streetcorner " << n << "." << endl;
            continue;
        }
        aa[0] = 1;
        vis[1] = true;
        dfs(1, 1);
        cout << "There are " << cnt << " routes from the " << 
        "firestation to streetcorner " << n << "." << endl;
    }
    return 0;
}