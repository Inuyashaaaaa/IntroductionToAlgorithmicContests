#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

const int maxn = 1e5 + 40;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node() :left(NULL), right(NULL) {}
};

int post[maxn];
int in[maxn];

Node* createNode(int postL, int postR, int inL, int inR) {
	if (postL > postR)
		return NULL;
	Node* root = new Node();
	root->val = post[postR];
	int pos = inL - 1;
	for (int i = inL; i <= inR; i++) {
		pos = i;
		if (in[i] == root->val)
			break;
	}
	int lCnt = pos - inL;
	root->left = createNode(postL, postL + lCnt - 1, inL, pos - 1);
	root->right = createNode(postL + lCnt, postR - 1, pos + 1, inR);

	return root;
}

int minn = 0x7fffffff;
int val = 0x7fffffff;
void dfs(Node* root,int sum = 0) {
	sum += root->val;
	if (root->left == NULL && root->right == NULL) {
		if (sum < minn || ( sum == minn && root->val < val)) {
			minn = sum;
			val = root->val;
		}
	}
	if (root->left)
		dfs(root->left, sum);
	if (root->right)
		dfs(root->right, sum);
}


int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		minn = 0x7fffffff;
		val = 0x7fffffff;
		stringstream ss(s1);
		int x;
		int cnt = 0;
		while (ss >> x) {
			in[cnt++] = x;
		}
		cnt = 0;
		stringstream ss2(s2);
		while (ss2 >> x) {
			post[cnt++] = x;
		}
		Node* root = createNode(0, cnt - 1, 0, cnt - 1);
		queue<Node*> q;
		q.push(root);
		dfs(root);
		cout << val << endl;	
	}
}