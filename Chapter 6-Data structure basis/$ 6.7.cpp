#include<bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node() :value(0), left(NULL), right(NULL) {}
};
Node* root;
vector<int> vec;
int readNode();
bool buildBinaryTree(string&, const int&);
bool traversalBinaryTree();

// 0代表结束输入 1代表错误 2代表正确
int readNode() {
	vec.clear();
	root = new Node();
	string s;
	int flag = 1;
	while (1) {
		if (!(cin >> s))
			return 0;
		if (s == "()") {
			if (flag != 3)
				flag = 2;
			else
				flag = 1;
			break;
		}
		stringstream ss(s);
		char ch;
		ss >> ch; //读掉左括号
		int value;
		ss >> value; //读节点的值
		ss >> ch; //读掉逗号
		ss >> s; //读掉剩下的
		if (!buildBinaryTree(s, value))
			flag = 3;
	}
	return flag;
}

bool buildBinaryTree(string& s, const int& v) {
	int len = s.length();
	Node* node = root;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'L') {
			if (!node->left) {
				node->left = new Node();
			}
			node = node->left;
		}
		else if (s[i] == 'R') {
			if (!node->right) {
				node->right = new Node();
			}
			node = node->right;
		}
		else {
			if (node->value)
				return false;
			node->value = v;
		}
	}
	return true;
}

bool traversalBinaryTree() {
	Node* node = root;
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node* temp = q.front();
			q.pop();
			if (!temp->value)
				return false;
			vec.push_back(temp->value);
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
	return true;
}

void removeTree(Node* node = root) {
	if (node == NULL)
		return;
	removeTree(node->left);
	removeTree(node->right);
	node = NULL;
	delete node;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	while (t = readNode()) {
		if (t == 1) {
			cout << "not complete" << endl;
		}
		else if (traversalBinaryTree()) {
			bool isFirst = false;
			for (auto& num : vec) {
				if (isFirst)
					cout << " ";
				cout << num;
				isFirst = true;
			}
			cout << endl;
		}
		else {
			cout << "not complete" << endl;
		}
		removeTree();
	}
}