#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define INF 0x7fffffff
using namespace std;


//1≤n≤300
const int maxn = 3e2 + 10;
vector<int> G[maxn];
bool vis[maxn];

int solve(int u) {
    bool isEnd = true;
    int maxn = 0;
    int sum = 0;
    for(auto& num: G[u]) {
        if(!vis[num]) {
            isEnd = false;
            vis[num] = true;
            int ret = solve(num);
            sum += ret;
            maxn = max(maxn, ret);
        }
    }
    if(isEnd) {
        return 0;
    } else {
        return sum - maxn + 1;
    }
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ms(vis);
    vis[1] = true;
    cout << solve(1) << endl;
    return 0;
}