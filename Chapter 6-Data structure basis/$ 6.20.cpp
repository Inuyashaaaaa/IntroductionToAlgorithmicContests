#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

const int maxn = 1e5 + 20;
int d[maxn];    //存距离
int vis[maxn];

vector<int> ans;
vector<unordered_map<int, int>> vec; //储存数据

//反向bfs
void bfs1(int n, int& dis) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	while (!q.empty()) {
		dis++;
		int size = q.size();
		vector<int> del;
		while (size--) {
			int x = q.front();
			q.pop();
			if (x == 1)
				return;
			for (auto& pair : vec[x]) {
				if (!vis[pair.first]) {
					q.push(pair.first);
					del.push_back(pair.first);
					d[pair.first] = dis;
				}
			}
		}
		for (auto& num : del)
			vis[num] = 1;
	}
}

//正向bfs
void bfs2(int n, int dis) {
	queue<int> q;
	q.push(1);
	memset(vis, 0, sizeof(vis));
	vis[1] = true;
	while (!q.empty()) {
		dis--;
		int size = q.size();
		vector<int> del;
		int minn = INF;
		queue<int> qq = q;
		for (int i = 0; i < size; i++) {
			int x = qq.front();
			if (x == n)
				return;
			qq.pop();
	
			for (auto& pair : vec[x]) {
				if (d[pair.first] == dis && !vis[pair.first])
					minn = min(minn, pair.second);//寻找最小color
			}
		}
		ans.push_back(minn);
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();

			for (auto& pair : vec[x]) {
				if (d[pair.first] == dis && !vis[pair.first]) {
					if (pair.second == minn) {
						q.push(pair.first);
						vis[pair.first] = true;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	while (cin >> n >> m) {
		ans.clear();
		vec.clear();
		memset(d, 0, sizeof(d));
		vec.resize(maxn);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (vec[a].count(b)) {
				if (vec[a][b] > c) {
					vec[a][b] = c;
					vec[b][a] = c;
				}
			}
			else {
				vec[a][b] = c;
				vec[b][a] = c;
			}
		}
		int dis = 0;
		bfs1(n, dis);
		dis--;
		bfs2(n, dis);
		cout << dis << endl;
		bool first = true;
		for (auto& num : ans) {
			if (!first) cout << " ";
			cout << num;
			first = false;
		}
	}
}