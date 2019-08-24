#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<list>
using namespace std;

const int maxn = 10;

//dir 0 1 2 3  => N E S W => 向上进来的
enum dir { N, E, S, W };

//保存状态，是否被踩过了
bool has[maxn][maxn][4][3];

struct Node {
	int x, y;
	dir Dir; //当前节点的x y 值以及朝向
	Node* parent; //当前节点的父亲节点
	Node(int x, int y, dir Dir, Node* parent) :
		x(x), y(y), Dir(Dir), parent(parent) {}
};

dir getDir(char ch) {
	if (ch == 'N')
		return dir::N;
	if (ch == 'E')
		return dir::E;
	if (ch == 'W')
		return dir::W;
	if (ch == 'S')
		return dir::S;
}

int getLRF(char ch) {
	if (ch == 'L')
		return 0;
	if (ch == 'R')
		return 1;
	if (ch == 'F')
		return 2;
}

int xEnd, yEnd;

void getNextPos(int& x, int& y, dir d) {
	if (d == dir::N) {
		x -= 1;
	}
	if (d == dir::E) {
		y += 1;
	}
	if (d == dir::S) {
		x += 1;
	}
	if (d == dir::W) {
		y -= 1;
	}
}

dir getNextdir(dir d, int LRF) {
	if (LRF == 2) return d;
	if (LRF == 1) return dir((d + 1) % 4);
	if (LRF == 0) return dir((d + 4 - 1) % 4);
}

Node *ret = NULL;

bool bfs(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node* temp = q.front();
			q.pop();
			int x = temp->x;
  			int y = temp->y;	
			dir d = temp->Dir;
			getNextPos(x, y, d);
			if (x == xEnd && y == yEnd) {
				ret = temp;
				return true;
			}
			if (x < 0 || x > 9 || y < 0 || y > 9)
				continue;
			for (int i = 0; i < 3; i++) {
				if (has[x][y][d][i]) {
					Node* node = new Node(x, y, getNextdir(d,i), temp);
					has[x][y][d][i] = false;
					q.push(node);

				}
			}
			
		}
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	while (cin >> s) {
		ret = NULL;
		if (s == "END")
			break;
		memset(has, false, sizeof(has));
		int x, y;
		cin >> x >> y;
		char ch;
		cin >> ch;
		Node* beginPos = new Node(x, y, getDir(ch), NULL);
		cin >> xEnd >> yEnd;
		while (cin >> x  && x) {
			cin >> y;
			while (cin >> ch && ch != '*') {
				string temp;
				cin >> temp;
				dir d = getDir(ch);
				for (int i = 0; i < temp.size(); i++) {
					has[x][y][d][getLRF(temp[i])] = true;
				}
			}
		}
		
		cout << s ;
		if (bfs(beginPos)) {
			list<pair<int,int>> l;
			l.push_back(make_pair(xEnd, yEnd));
			while (ret) {
				l.push_front(make_pair(ret->x, ret->y));
				ret = ret->parent;
			}
			int cnt = 0;
			for (auto& pair : l) {
				if (cnt % 10 == 0)
					cout << endl << " ";
				cout << " (" << pair.first << "," << pair.second << ")" ;
				cnt++;
			}
			cout << endl;
		}
		else {
			cout << endl;
			cout << "  No Solution Possible" << endl;
		}
		int m = 1;
	}
}