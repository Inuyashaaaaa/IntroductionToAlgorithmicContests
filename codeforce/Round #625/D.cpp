#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e5 + 10;

vector<int> edge1[maxn];        // 实际的
vector<int> edge2[maxn];        // 反向的
int depth[maxn];
vector<int> path;     
int k, n, m;    


void bfs(int root) {
    int d = 0;
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(root);
    vis[root] = true;
    depth[root] = 0;
    while(!q.empty()) {
        int sz = q.size();
        d++;
        for(int i = 0; i < sz; i++) {
            int t = q.front();
            q.pop();
            for(auto& v: edge2[t]) {
                if(!vis[v]) {
                    depth[v] = d;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge1[a].push_back(b);
        edge2[b].push_back(a);
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;
        path.push_back(a);
    }
    bfs(path[k - 1]);
    int ans1 = 0;
    int ans2 = 0;
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    vis[path[0]] = true;
    // for(int i = 1; i <= n; i++) {
    //     cout << depth[i] << endl;
    // }
    for(int i = 0; i < k - 1; i++) {
        if (depth[path[i]] != depth[path[i + 1]] + 1)
            ++ans1;
        for (int v : edge1[path[i]]) {
            if (v != path[i + 1] && depth[path[i]] == depth[v] + 1) {
                ++ans2;
                break;
            }
        }
        

    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}