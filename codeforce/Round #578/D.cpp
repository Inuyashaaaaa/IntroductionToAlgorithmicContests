#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 2000 + 20;
char Map[maxn][maxn];
struct info {
	int begin;
	int end;
	info() {
		begin = 0;
		end = 0;
	}
};
info rows[maxn];
info cols[maxn];
int cnt[maxn][maxn];

/*
4 2
BWWW
WBBW
WBBW
WWWB//

 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> Map[i] + 1;
	}

	//左右
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Map[i][j] == 'B') {
				rows[i].begin = j;
				break;
			}
		}
		for (int j = n; j >= 1; j--) {
			if (Map[i][j] == 'B') {
				rows[i].end = j;
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (Map[j][i] == 'B') {
				cols[i].begin = j;
				break;
			}
		}
		for (int j = n; j >= 1; j--) {
			if (Map[j][i] == 'B') {
				cols[i].end = j;
				break;
			}
		}
	}

	int maxn = 0;
	int index = 0;
	int indexj = 0;

	int haveR = 0;
	for (int i = 1; i <= n; i++) {
		if (rows[i].begin == 0)
			haveR++;
	}
	for (int i = 1; i <= n - k + 1; i++) {
		//for rows
		int res = 0;
		for (int j = 1; j <= k; j++) {
			if (i <= rows[j].begin && rows[j].end < i + k) {
				res++;
			}
		}
		for (int j = 1; j <= n - k + 1; j++) {
			if (j > 1) {
				res -= i <= rows[j - 1].begin && rows[j - 1].end < i + k;
				res += i <= rows[j + k - 1].begin && rows[j + k - 1].end < i + k;
			}
			cnt[i][j] = res + haveR;
		}
	}
	int haveC = 0;
	for (int i = 1; i <= n; i++) {
		if (cols[i].begin == 0)
			haveC++;
	}
	int ans = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		//for rows
		int res = 0;
		for (int j = 1; j <= k; j++) {
			if (i <= cols[j].begin && cols[j].end < i + k) {
				res++;
			}
		}
		for (int j = 1; j <= n - k + 1; j++) {
			if (j > 1) {
				res -= i <= cols[j - 1].begin && cols[j - 1].end < i + k;
				res += i <= cols[j + k - 1].begin && cols[j + k - 1].end < i + k;
			}
			;
			ans = max(ans, cnt[j][i] + res + haveC);
		}
	}

	cout << ans << endl;
	//system("pause");
}