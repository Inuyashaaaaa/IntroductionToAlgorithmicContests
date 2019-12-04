#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 10;

struct Degree {
    int d;
    int id;
    friend bool operator < (const Degree& d1, const Degree& d2) {
        return d1.d > d2.d;
    }
}d[maxn];

int vis[maxn];
bool v[maxn];
int k;
unordered_map<int, int> mp[maxn];

void dfs(int u) {
    ms(v);
    vector<int> vec;
    for(auto& num: mp[u]) {
        int n = num.first;
        if(vis[n]) v[vis[n]] = 1;
        else vec.push_back(n);
    }
    for(int i = 1; i <= k; i++) {
        if(!v[i]) {
            vis[u] = i;
            break;
        }
    }
    for(int i = 0; i < vec.size(); i++) {
        dfs(vec[i]);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        for(int i = 0; i <= n; i++) {
            mp[i].clear();
        }
        ms(d);
        ms(vis);
        int a, b;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            if(mp[a].count(b)) continue;
            mp[a][b] = mp[b][a] = 1; 
            d[a].id = a;
            d[a].d++;
            d[b].id = b;
            d[b].d++;     
        }
        sort(d + 1, d + n + 1);
        k = (d[1].d % 2 == 0 ? d[1].d + 1 : d[1].d);
        cout << k << endl;
        dfs(1);
        for(int i = 1; i <= n; i++) {
            cout << vis[i] << endl;
        }
    }
    return 0;
}