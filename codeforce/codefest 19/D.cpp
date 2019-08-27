#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define EXP 1e-6
const int maxn = 1e5 * 2 + 10;

bool use[maxn];
LL a[maxn];

int main() {
	vector<int> ans;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	memset(use, false, sizeof(use));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		int t = ((1 + sqrt(8 * a[i] + 1)) / 2 - EXP) + 1;
		while (use[t]) t++;
		ans.push_back(t);
		use[t] = true;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}