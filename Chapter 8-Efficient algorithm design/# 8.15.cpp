#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const LL maxn = 2e5 + 10;
LL a[maxn];
LL _left[maxn];
LL _right[maxn];
LL n;

// [l, r]
bool solve(LL l, LL r) {
	if (l >= r) return true;
	LL ll = l, rr = r;
	LL mid = ll + (rr - ll) / 2;
	while (ll <= mid) {
		if ((_left[ll] == -1 || _left[ll] < l ) && (_right[ll] == -1 || _right[ll] > r)) {
			if (solve(l, ll - 1) && solve(ll + 1, r)) return true;
			break;
		}
		else if ((_left[rr] == -1 || _left[rr] < l) && (_right[rr] == -1 || _right[rr] > r)) {
			if (solve(l, rr - 1) && solve(rr + 1, r)) return true;
			break;
		}
		ll++;
		rr--;
	}
	return false;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (LL i = 0; i < n; i++) {
			cin >> a[i];
		}
		// left
		unordered_map<LL, LL> s;
		for (LL i = 0; i < n; i++) {
			if (!s.count(a[i])) {
				_left[i] = -1;
				s[a[i]] = i;
			}
			else {
				_left[i] = s[a[i]];
				s[a[i]] = i;
			}
		}

		// right
		s.clear();
		for (LL i = n - 1; i >= 0; i--) {
			if (!s.count(a[i])) {
				_right[i] = -1;
				s[a[i]] = i;
			}
			else {
				_right[i] = s[a[i]];
				s[a[i]] = i;
			}
		}
		if (solve(0, n - 1)) {
			cout << "non-boring" << endl;
		}
		else {
			cout << "boring" << endl;
		}
	}
	return 0;
}