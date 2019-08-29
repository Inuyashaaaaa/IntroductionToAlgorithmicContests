#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int p[1100];
unordered_map<int, int> m;

//并查集
void init() {
	for (int i = 0; i < 26; i++)
		p[i] = i;
}

int find(int a) {
	while (a != p[a])
		a = p[a];
	return a;
}

void merge(int a, int b) {
	int c = find(a);
	int d = find(b);
	if (c != d)
		p[d] = c;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, b, c;
	int kase = 0;
	while (cin >> a >> b >> c && (a || b || c)) {
		cout << "Case " << ++kase << ": ";
		m.clear();
		init();
		int x, y;
		int ans = b;
		while (b--) {
			cin >> x >> y;
			merge(x, y);
			if (m.count(x)) m[x]++;
			else m[x] = 1;
			if (m.count(y)) m[y]++;
			else m[y] = 1;
		}
		vector<int> parent;
		int size = 0;
		for (int i = 1; i <= a; i++) {
			if (i == find(i) && m.count(i)) {
				size++;
				parent.push_back(i);
			}
		}
		// 不同集合个数加入 vector
		vector<vector<int>> vec;
		vec.resize(size);
		for (int i = 1; i <= a; i++) {
			int num = find(i);
			for (int j = 0; j < size; j++) {
				if (parent[j] == num) {
					vec[j].push_back(i);
					break;
				}
			}
		}

		for (int i = 0; i < size; i++) {
			int cnt = 0;
			for (auto& num : vec[i]) {
				if (m[num] % 2 == 1) cnt++;
			}
			ans += cnt > 3 ? (cnt - 1) / 2: 0;
		}
		ans += size ? size - 1 : 0;
		ans *= c;
		cout << ans << endl;
	}
}