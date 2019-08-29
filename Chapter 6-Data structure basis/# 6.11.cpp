#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int pos[maxn];
vector<vector<int>> tree;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while (cin >> n) {
		int x;
		tree.resize(maxn);
		for (int i = 1; i <= n; i++) {
			cin >> x;
			pos[x] = i;
			tree[i].clear();
		}
		stack<int> s;
		cin >> x;
		int root = x;
		s.push(root);
		for (int i = 2; i <= n; i++) {
			cin >> x;
			while (1) {
				int top = s.top();
				if (top == root || pos[x] > pos[top] + 1) {
					s.push(x);
					tree[top].push_back(x);
					break;
				}
				else {
					s.pop();
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << i << ":";
			for (auto& num : tree[i])
				cout << " " << num;
			cout << endl;
		}
	}
}