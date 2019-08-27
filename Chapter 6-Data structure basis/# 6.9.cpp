#include<bits/stdc++.h>
using namespace std;

struct Card {
	stack<string> s;
	int left, right;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cnt = 0;
	string s;

	while (cin >> s) {
		if (s == "#") break;
		cnt = 0;
		Card c[53];
		c[cnt].left = cnt - 1;
		c[cnt].right = cnt + 1;
		c[cnt].s.push(s);
		cnt++;

		while (cin >> s) {
			c[cnt].left = cnt - 1;
			c[cnt].right = cnt + 1;
			c[cnt].s.push(s);
			cnt++;
			if (cnt == 52) break;
		}
		bool vis[52] = { 0 };
		for (int i = 0; i < cnt; i++) {
			if (vis[i]) continue;
			int index = i;
			for (int j = 0; j < 3; j++) {
				index = c[index].left;
				if (index == -1) break;
			}
			//三张牌
			if (index != -1) {
				if (c[index].s.top()[0] == c[i].s.top()[0] ||
					c[index].s.top()[1] == c[i].s.top()[1]) {
					c[index].s.push(c[i].s.top());
					c[i].s.pop();
					if (c[i].s.empty()) {
						c[c[i].left].right = c[i].right;
						if (c[i].right != 52)
							c[c[i].right].left = c[i].left;
						vis[i] = true;
					}
					i = -1;
					continue;
				}
			}
			index = c[i].left;
			//一张牌
			if (index != -1) {
				if (c[index].s.top()[0] == c[i].s.top()[0] ||
					c[index].s.top()[1] == c[i].s.top()[1]){
					c[index].s.push(c[i].s.top());
					c[i].s.pop();
					if (c[i].s.empty()) {
						c[c[i].left].right = c[i].right;
						if (c[i].right != 52)
							c[c[i].right].left = c[i].left;
						vis[i] = true;
					}
					i = -1;
					continue;
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < cnt; i++) {
			if (!vis[i])
				ans.push_back(i);
		}
		int size = ans.size();
		cout << size << " pile" << (size > 1 ? "s" : "") << " remaining:";
		for (auto& num : ans) {
			cout << " " << c[num].s.size();
		}
		cout << endl;
	}
}

