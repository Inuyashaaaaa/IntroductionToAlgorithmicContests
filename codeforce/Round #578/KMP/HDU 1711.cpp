#include<bits/stdc++.h>
using namespace std;

const int maxn1 = 1e6 + 1000;
const int maxn2 = 1e4 + 10;
int a[maxn1];

int b[maxn2];
int prefix[maxn2];

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		//KMP
		int k = 0;
		for (int i = 2; i <= m; i++) {
			while (k && b[i] != b[k + 1]) k = prefix[k];
			if (b[i] != b[k + 1]) {
				prefix[i] = 0;
			}
			else {
				k++;
				prefix[i] = k;
			}
		}
		// for(int i = 1; i <= m ;i++) {
		//     cout << prefix[i] << " ";
		// }

		k = 0;
		bool flag = false;
		int j;
		for (j = 1; j <= n ; j++) {
			while (a[j] != b[k + 1] && k) k = prefix[k];
			if (a[j] != b[k + 1]) {
				k = 0;
			}
			else {
				k++;
			}
			if (k == m) {
				flag = true;
				break;
			}
		}

		cout << (flag ? j - m + 1 : -1) << endl;
	}
	//system("pause");
	return 0;
}