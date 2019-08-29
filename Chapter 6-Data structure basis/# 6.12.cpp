#include<bits/stdc++.h>
using namespace std;
const int maxn = 10 + 10;
int pic[maxn][maxn];
int r, c, beginX, beginY, top, _forward;
int bottom, _left, _right, _back;
int confirmLeft[7][7];
bool vis[maxn][maxn][7][7]; //以36种方式访问

struct Node {
	int x, y;
	Node* parent;
	int left, right, top, bottom, forward, back;
	Node() {}
	Node(int x, int y, Node* root) :x(x), y(y), parent(root) {}
};

//初始化确认左数组
void initArr() {
	confirmLeft[5][1] = 3; confirmLeft[1][2] = 3; confirmLeft[2][6] = 3; confirmLeft[6][5] = 3;
	confirmLeft[1][5] = 4; confirmLeft[2][1] = 4; confirmLeft[6][2] = 4; confirmLeft[5][6] = 4;
	confirmLeft[2][3] = 1; confirmLeft[3][5] = 1; confirmLeft[5][4] = 1; confirmLeft[4][2] = 1;
	confirmLeft[3][2] = 6; confirmLeft[5][3] = 6; confirmLeft[4][5] = 6; confirmLeft[2][4] = 6;
	confirmLeft[4][6] = 2; confirmLeft[6][3] = 2; confirmLeft[3][1] = 2; confirmLeft[1][4] = 2;
	confirmLeft[6][4] = 5; confirmLeft[3][6] = 5; confirmLeft[1][3] = 5; confirmLeft[4][1] = 5;
}
//输入及确定骰子
void init() {
	memset(vis, 0, sizeof(vis));
	cin >> r >> c >> beginX >> beginY >> top >> _forward;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> pic[i][j];
		}
	}
	// 确定骰子
	_back = 7 - _forward;
	bottom = 7 - top;
	_left = confirmLeft[top][_forward];
	_right = 7 - _left;
}
//i = 1, 2, 3, 4 表示上 左 右 下
void turnDir(int i, int& top, int& bottom, int& left, int& right, int& forward, int& back, int& x, int& y) {
	int temp;
	//向下 
	if (i == 1) {
		temp = bottom;
		bottom = forward;
		forward = top;
		top = back;
		back = temp;
		x++;
	}
	//向左
	if (i == 2) {
		temp = bottom;
		bottom = left;
		left = top;
		top = right;
		right = temp;
		y++;
	}
	//向右
	if (i == 3) {
		temp = bottom;
		bottom = right;
		right = top;
		top = left;
		left = temp;
		y--;
	}
	//向上
	if (i == 4) {
		temp = bottom;
		bottom = back;
		back = top;
		top = forward;
		forward = temp;
		x--;
	}
}

int cnt = 0;
int size1 = 0;
void getSize(Node* root) {
	while (root ->parent) {
		size1++;
		root = root->parent;
	}
}
//(1,2),(2,2),(2,3),(3,3),(3,2),(3,1),(2,1),(1,1),(1,2)
void print(Node* root) {
	if (root == NULL) return;
	print(root->parent);
	if (cnt % 9 == 0 && cnt)
		cout << endl;
	if(cnt % 9 == 0)
	cout << "  (" << root->x << "," << root->y << ")";
	else
	cout << "(" << root->x << "," << root->y << ")";
	if (cnt != size1)
		cout << ",";
	cnt++;
}

bool bfs() {
	size1 = 0;
	cnt = 0;
	queue<Node*> q;
	Node* root = new Node(beginX, beginY, NULL);
	root->back = _back;
	root->bottom = bottom;
	root->forward = _forward;
	root->top = top;
	root->left = _left;
	root->right = _right;
	q.push(root);
	bool begin = false;
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		//cout << temp->x << " " << temp->y << endl;
		//cout << temp->top << endl;
		if (temp->x == beginX && temp->y == beginY && begin) {
			getSize(temp);
			print(temp);
			return true;
		}
		for (int i = 1; i <= 4; i++) {
			Node* temp2 = new Node();
			temp2->back = temp->back; temp2->bottom = temp->bottom;
			temp2->forward = temp->forward; temp2->left = temp->left;
			temp2->parent = temp2->parent; temp2->right = temp->right;
			temp2->top = temp->top; temp2->x = temp->x; temp2->y = temp->y;
			turnDir(i, temp2->top, temp2->bottom, temp2->left, temp2->right,
				temp2->forward, temp2->back, temp2->x, temp2->y);
			if (temp2->x < 1 || temp2->x > r || temp2->y < 1
				|| temp2->y > c || pic[temp2->x][temp2->y] == 0) continue;
			if (temp->top != pic[temp2->x][temp2->y]
				&& pic[temp2->x][temp2->y] != -1) continue;
			if (!vis[temp2->x][temp2->y][temp2->top][temp2->forward]) {
				q.push(temp2);
				temp2->parent = temp;
				vis[temp2->x][temp2->y][temp2->top][temp2->forward] = 1;
			}
		}
		begin = true;
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	initArr();
	string s;
	while (cin >> s && s != "END") {
		init();
		Node root;
		cout << s << endl;
		if (bfs()) {
			int k = 1;
		}
		else {
			cout << "  No Solution Possible" ;
		}
		cout << endl;
	}
}