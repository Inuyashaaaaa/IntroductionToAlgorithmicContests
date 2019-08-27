#include<bits/stdc++.h>
#define LL long long
using namespace std;

string s;
LL len;
LL cnt;
unordered_map<LL, LL> m;

void dfs(int depth) {
	char ch;
	if (cin.peek() == '[') {
		cin >> ch;
		dfs(depth + 1);
		cin >> ch; //逗号
		dfs(depth + 1);
		cin >> ch; //右括号
		return;
	}
	LL x;
	cin >> x;
	cnt++;
	x <<= depth;
	m[x]++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	LL T;
	cin >> T;
	while (T--) {
		cin.get();
		m.clear();
		int depth = 0;
		cnt = 0;
		dfs(depth);
		LL maxn = 0;
		for (auto& pair : m) {
			maxn = max(pair.second, maxn);
		}
		cout << cnt - maxn << endl;
	}
}