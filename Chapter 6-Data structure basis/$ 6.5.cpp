#include<iostream>
#include<iomanip>
using namespace std;

const int maxn = 1e5 + 100;
int Left[maxn];
int Right[maxn];
int rev = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	long long n, q;
	int kase = 0;
	while (cin >> n >> q) {
		cout << "Case " << ++kase << ": ";
		rev = 0;
		for (int i = 1; i <= n; i++) {
			Left[i] = i - 1;
			Right[i] = (i + 1) % (n + 1);
		}
		Left[1] = 0;
		Right[n] = 0;
		Right[0] = 1;
		Left[n + 1] = n;
		while (q--) {
			int opt;
			cin >> opt;
			if (opt == 4) {
				rev = !rev;
				continue;
			}
			int a, b;
			cin >> a >> b;
			if (a == b)
				continue;
			int aLeft = Left[a];
			int aRight = Right[a];
			int bLeft = Left[b];
			int bRight = Right[b];
			if (opt == 3 && (Left[a] == b || Left[b] == a)) {
				if (Left[b] == a) {
					Right[aLeft] = b;
					Left[b] = aLeft;
					Right[b] = a;
					Left[a] = b;
					Right[a] = bRight;
					Left[bRight] = a;
				}
				else {
					Right[bLeft] = a;
					Left[a] = bLeft;
					Right[a] = b;
					Left[b] = a;
					Right[b] = aRight;
					Left[aRight] = b;
				}
				continue;
			}
			if (opt == 3) {
				Right[aLeft] = b;
				Left[aRight] = b;
				Right[bLeft] = a;
				Left[bRight] = a;
				Left[a] = bLeft;
				Right[a] = bRight;
				Left[b] = aLeft;
				Right[b] = aRight;
				continue;
			}
			if (rev)
				opt = 3 - opt;

			if (opt == 2 && Right[b] != a) {
				Right[b] = a;
				Left[a] = b;
				Right[a] = bRight;
				Left[aRight] = aLeft;
				Right[aLeft] = aRight;
				Left[bRight] = a;
				continue;
			}

			if (opt == 1 && Right[a] != b) {
				Right[a] = b;
				Left[a] = bLeft;
				Left[b] = a;
				Right[aLeft] = aRight;
				Left[aRight] = aLeft;
				Right[bLeft] = a;
				continue;
			}		
		}		
		long long ans = 0;
		int cnt = 1;
		for (int i = Right[0]; i;) {
			if (cnt % 2 == 1)
				ans += i;
			cnt++;
			i = Right[i];
		}
		if (rev && n % 2 == 0) ans = (n * (n + 1) / 2) - ans;
		cout << ans << endl;
	}
}
