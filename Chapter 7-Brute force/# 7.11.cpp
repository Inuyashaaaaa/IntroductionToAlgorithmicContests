#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 15;

int n, m, s, t;
int state = 0;
bool vis[32768][maxn];
bool G[maxn][maxn];
struct Node {
	int state; // 障碍物状态
	int robot; // 机器人位置
	Node* parent;
};

void printAns(Node* cur, Node* parent) {
	if (parent == NULL) return;
	printAns(cur->parent, parent->parent);
	if (cur->robot == parent->robot) {
		int a, b;
		//b代表走到的地方
		//a代表起始
		for (int i = 0; i < maxn; i++) {
			if ((cur->state & (1 << i)) != (parent->state & (1 << i))) {
				if (cur->state & (1 << i)) {
					b = i + 1;
				}
				else {
					a = i + 1;
				}
			}
		}
		cout << a << " " << b << endl;
	}
	else {
		cout << parent->robot + 1 << " " << cur->robot + 1 << endl;
	}
	return;
}

int getDepth(Node* cur) {
	if (cur->parent == NULL)
	return 0;
	return 1 + getDepth(cur->parent);
}

void bfs() {
	queue<Node*> q;
	Node* root = new Node();
	root->state = state;
	root->robot = s;
	root->parent = NULL;
	q.push(root);
	while (!q.empty()) {
		//n个结点尝试走动
		Node* n1 = q.front();
		if (n1->robot == t) {
			cout << getDepth(n1) << endl;
			printAns(n1, n1->parent);
			cout << endl;
			return;
		}
		q.pop();
		for (int i = 0; i < n; i++) {
			if ((n1->state & (1 << i)) == 0 && (n1->robot != i)) continue; //这个节点没有东西
			for (int j = 0; j < n; j++) {
				if ((n1->state & (1 << j)) || (n1->robot == j)) continue; //这个节点有东西了
				if (!G[i][j]) continue; //没路线
				//cout << i + 1 << "->" << j + 1 << endl;
				int state = n1->state;
				int robot = n1->robot;
				Node* n2 = new Node();
				n2->parent = n1;
				if (n1->robot == i) {
					robot = j;
				}
				else {
					state &= (~(1 << i));
					state |= (1 << j);
				}
				if (vis[state][robot]) continue;
				vis[state][robot] = true;
				n2->robot = robot;
				n2->state = state;
				q.push(n2);
			}
		}
	}
	cout << "-1" << endl;
	cout << endl;
	return;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		cout << "Case " << ++kase << ": ";
		if (kase == 24) {
			int k = 1;
		}
		//当前位置s 下个位置t
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		state = 0;
		cin >> n >> m >> s >> t;
		s--;
		t--;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			state |= (1 << (x - 1));
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			G[a - 1][b - 1] = G[b - 1][a - 1] = true;
		}
		vis[state][s] = true;
		bfs();
	}
	return 0;
}