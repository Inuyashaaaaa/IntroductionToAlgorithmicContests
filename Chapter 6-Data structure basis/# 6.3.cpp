#include<bits/stdc++.h>
using namespace std;

struct Node {
	char ch;
	Node *left, *right;
};

string pre, in;

Node* createNode(int preL, int preR, int inL, int inR) {
	if (preL > preR) return NULL;
	Node* root = new Node();
	char ch = pre[preL];
	root->ch = ch;
	int i;
	for (i = inL; i <= inR; i++) {
		if (ch == in[i])
			break;
	}
	int cnt = i - inL;
	root->left = createNode(preL + 1, preL + cnt, inL, i - 1);
	root->right = createNode(preL + cnt + 1, preR, i + 1, inR);
	return root;
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->ch;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> pre >> in) {
		Node* root = createNode(0, pre.size() - 1, 0, in.size() - 1);
		postOrder(root);
		cout << endl;
	}
	return 0;
}