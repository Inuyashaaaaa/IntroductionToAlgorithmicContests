#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int maxn = 10000 + 10;
int in[maxn], post[maxn];

struct Node {
	int val;
	Node *left, *right;
	Node() :val(0), left(NULL), right(NULL) {}
};

Node* createNode(int postL, int postR, int inL, int inR) {
	if (postL > postR) return NULL;
	Node* root = new Node();
	root->val = post[postR];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == root->val)
			break;
	}
	int lCnt = i - inL;
	root->left = createNode(postL, postL + lCnt - 1, inL, i - 1);
	root->right = createNode(postL + lCnt, postR - 1, i + 1, inR);
	return root;
}

int minN = INF;
int minV = INF;

void dfs(Node* root, int sum) {
    sum += root->val;
	if (root->left == NULL &&
		root->right == NULL) {
		if (sum < minN || (sum == minN && root->val < minV)) {
			minN = sum;
			minV = root->val;
			return;
		}
	}
	if (root->left) {
		dfs(root->left, sum);
	}
	if (root->right) {
		dfs(root->right, sum);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s1, s2;
	while (getline(cin, s1)) {
		minN = INF;
		minV = INF;
		getline(cin, s2);
		stringstream ss1(s1);
		int x;
		int cnt = 0;
		while (ss1 >> x) {
			in[cnt++] = x;
		}
		stringstream ss2(s2);
		cnt = 0;
		while (ss2 >> x) {
			post[cnt++] = x;
		}
		Node* root = createNode(0, cnt - 1, 0, cnt - 1);
		int sum = 0;
		dfs(root, sum);
		cout << minV << endl;
	}
	return 0;
}