#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
vector<int> edge[maxn];
int deg[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int num = n;
    while(num > 1) {
        int u, v;
        for(u = 1; 1 != deg[u]; u++);
        for(v = u + 1; 1 != deg[v]; v++);
        cout << "? " << u << " " << v << endl;
        cout.flush();
        int k;
        cin >> k;
        if(k == u || k == v) {
            cout << "! " << k << endl;
            return 0;
        }
        for(int& uu: edge[u]) {
            deg[uu]--;
        }
        for(int& vv: edge[v]) {
            deg[vv]--;
        }
        deg[u] = deg[v] = -1;
        num -= 2;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }

    return 0;
}