#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 5000 + 50;
int G[maxn][maxn];
int n, m;
int vis[maxn];

bool dfs(int u) {
	vis[u] = -1; //正在访问 
	for (int v = 1; v <= n; v++) {
		if (G[u][v] == 0) {
			G[u][v] = 1;
			if (vis[v] < 0){
				G[u][v] = 2;
				return false;
			}
			if (!vis[v] && !dfs(v)) return false;
		}
	}
	vis[u] = 1;
	return true;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(G, -1, sizeof(G)); //没走过
    vector<pair<int, int>> p;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a][b] = 0;
        ans.push_back((a > b) + 1);
	}
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if(!dfs(i)) {
			ok = false;
			break;
		}
	}

	if(ok) {
		cout << "1" << endl;
		for(auto& num: ans) {
			cout << 1 << " ";
		}
		
	}
	else {
		cout << "2" << endl;
		for(auto& num: ans) {
			cout << num << " ";
		}
	}
    cout << endl;

	return 0;
}