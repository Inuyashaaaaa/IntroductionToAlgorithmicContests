#include<bits/stdc++.h>
using namespace std;

const int maxn = 10;
int dx[8] = { -1, -2, -1, -2, 1, 2, 1, 2 };
int dy[8] = { -2, -1 , 2 , 1, -2, -1, 2, 1 };
bool vis[10][10];
struct Point {
	int x, y;
};
int bfs(Point& begin, Point& end) {
	Point p = begin;
	queue<Point> q;
	q.push(p);
	vis[p.x][p.y] = true;
	int step = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Point temp = q.front();
			q.pop();
			if (temp.x == end.x && temp.y == end.y)
				return step;
			for (int i = 0; i < 8; i++) {
				Point temp2 = temp;
				temp2.x += dx[i];
				temp2.y += dy[i];
				if (temp2.x < 1 || temp2.y < 1
					|| temp2.x > 8 || temp2.y > 8
					|| vis[temp2.x][temp2.y])
					continue;
				q.push(temp2);
				vis[temp2.x][temp2.y] = true;
			}
		}
		step++;
	}
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	char ch1, ch2, ch3, ch4;
	while (cin >> ch1 >> ch2 >> ch3 >> ch4) {
		memset(vis, false, sizeof(vis));
		Point begin, end;
		begin.x = ch1 - 'a' + 1;
		begin.y = ch2 - '0';
		end.x = ch3 - 'a' + 1;
		end.y = ch4 - '0';
		cout << "To get from " << ch1 << ch2 <<
			" to " << ch3 << ch4 << " takes "<< 
		bfs(begin, end)  << " knight moves." << endl;
	}
}