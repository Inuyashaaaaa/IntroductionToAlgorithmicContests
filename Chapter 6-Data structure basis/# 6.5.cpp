#include<bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0 ,-1, 0 };
char pic[maxn][maxn];
bool vis[maxn][maxn];
int kase;

struct Point {
	int x, y;
	int now;
	friend bool operator < (const Point& p1,const Point& p2) {
		return p1.now > p2.now;
	}
};

bool bfs(int n, int m, int k, int& step) {
	priority_queue<Point> q;
	Point p;
	p.x = p.y = 1;
	p.now = 0;
	q.push(p);
	vis[1][1] = true;
	while (!q.empty()) {
		int size = q.size();
		priority_queue<Point> qqq = q;
		while (!q.empty())
			q.pop();
		for (int i = 0; i < size; i++) {
			Point temp = qqq.top();
			qqq.pop();
			//if (kase == 729){
		//		cout << temp.x << ":" << temp.y << endl;
		//		cout << temp.now << endl;
		//	}
			if (temp.x == n && temp.y == m)
				return true;
			for (int j = 0; j < 4; j++) {
				Point temp2 = temp;

				temp2.x += dx[j];
				temp2.y += dy[j];
				if (temp2.x < 1 || temp2.x > n
					|| temp2.y < 1 || temp2.y > m
					|| vis[temp2.x][temp2.y])
					continue;
				if (pic[temp2.x][temp2.y] == '1') {
					if (temp2.now < k) {
						temp2.now++;
						q.push(temp2);
						vis[temp2.x][temp2.y] = true;
					}
					else
						continue;
				}
				else {
					temp2.now = 0;
					q.push(temp2);
					vis[temp2.x][temp2.y] = true;
				}
			}
		}
		step++;
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	kase = 1;
	while (T--) {
		memset(vis, 0, sizeof(vis));
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> pic[i][j];
			}
		}
		int step = 0;
		cout << (bfs(n, m, k, step) ? step : -1) << endl;
	}
	return 0;
}