#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

vector<int> edge[maxn];
int dep[maxn];
int f[maxn][20];

// let vertext 1 as root
void dfs(int u, int parent) {
    dep[u] = dep[parent] + 1;
    for(int i = 1; (1 << i) <= dep[u]; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(auto& v: edge[u]) {
        if(v == parent) continue;
        f[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] == 0) continue;
        if(dep[f[x][i]] >= dep[y]) x = f[x][i];
        if(x == y) return x;
    }
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int dis(int x, int y) {
    if(x == y) return 0;
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dep[0] = 0;
    dfs(1, 0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b, x, y, k;
        cin >> x >> y >> a >> b >> k;
        int p = dis(a, b);
        int l = min(dis(a, x) + dis(b, y),
        dis(a, y) + dis(b, x)) + 1;
             
        // if(i == 1) {
        //     cout << ">>" << endl;
        //     cout << x << " " <<
        //             y << " " << 
        //             a << " " <<
        //             b << " " << 
        //             k << endl;
        //     cout << lca(1, 1) << endl;
        //     cout << lca(a, b) << endl;
        //     cout << dis(a, x) + dis(b, y) + 1 << endl;
        //     cout << dis(a, y) + dis(b, x) + 1 << endl;
        // }
        if((k >= p && (k - p) % 2 == 0) ||
        (k >= l && (k - l) % 2 == 0)) {
            cout << "YES\n";
        } 
        else {
            cout << "NO\n";
        }
    }
    return 0;
}