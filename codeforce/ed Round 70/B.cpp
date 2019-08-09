#include<iostream>
#include<algorithm>
#include<string>
#define INF 0x7fffffff
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int b[10];
			for (int k = 0; k < 10; k++) b[k] = INF;
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if (l || k) {
						b[(k * i + l * j) % 10] = min(b[(k * i + l * j) % 10], l + k - 1);
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < s.length() - 1; i++) {
				if (b[(s[i + 1] - s[i] + 10) % 10] == INF) {
					ans = -1;
					break;
				}
				ans += b[(s[i + 1] - s[i] + 10) % 10];
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}