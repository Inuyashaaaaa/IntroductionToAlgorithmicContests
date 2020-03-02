#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e5 + 10;
vector<int> vec;
vector<int> edge[maxn];
vector<int> dis1;
vector<int> dis2;
int n, m, k, x, a, b;

void bfs(int u, vector<int>& dis) {
    dis.assign(n + 1, -1);
    queue<int> q;
    dis[u] = 0;
    q.push(u);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        for(auto& vv: edge[v]) {
            if(dis[vv] != -1) continue;
            dis[vv] = dis[v] + 1;
            // cout << "dis[" << vv << "]: " << dis[vv] << endl; 
            q.push(vv);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    dis1.resize(maxn);
    dis2.resize(maxn);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> x;
        vec.push_back(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bfs(1, dis1);
    bfs(n, dis2);
    sort(vec.begin(), vec.end(), [&](int x, int y) {
        return dis1[x] - dis2[x] < dis1[y] - dis2[y];
    });
    x = dis1[vec[0]];
    int ans = -1;
    for(int i = 1; i < k; i++) {
        ans = max(ans, x + 1 + dis2[vec[i]]);
        x = max(x, dis1[vec[i]]);
    }
    ans = min(ans, dis1[n]);
    cout << ans << endl;
    return 0;
}