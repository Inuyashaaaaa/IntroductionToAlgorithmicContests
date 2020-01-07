#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 100;

struct Rec {
	int x, y, z;
	Rec(int x, int y, int z) : x(x), y(y), z(z) {}
	Rec() {}
}rec[maxn][3];

int d[maxn][3];
bool have_edge[maxn][3][maxn][3];
int n;

int dp(int i, int k) {
	int& ans = d[i][k];
	if (ans != -1) return ans;
	ans = rec[i][k].z;
	for (int j = 1; j <= n; j++) {
		for (int w = 0; w <= 2; w++) {
			if (have_edge[i][k][j][w]) {
				ans = max(ans, dp(j, w) + rec[i][k].z);
			}
		}
	}
	return ans;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int kase = 0;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> rec[i][0].x >> rec[i][0].y >> rec[i][0].z;
			rec[i][1].x = rec[i][0].y; rec[i][1].y = rec[i][0].z;
			rec[i][1].z = rec[i][0].x; rec[i][2].x = rec[i][0].z;
			rec[i][2].y = rec[i][0].x; rec[i][2].z = rec[i][0].y;
		}
		memset(d, -1, sizeof(d));
		ms(have_edge);
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= 2; k++) {
				for (int j = 1; j <= n; j++) {
					for (int w = 0; w <= 2; w++) {
						if ((rec[i][k].x > rec[j][w].x && rec[i][k].y > rec[j][w].y)
							||(rec[i][k].x > rec[j][w].y && rec[i][k].y > rec[j][w].x))
							have_edge[i][k][j][w] = true;
					}
				}
			}
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= 2; k++) {
				ans = max(ans, dp(i, k));
			}
		}
		//Case 1: maximum height =
		std::cout << "Case " << ++kase << ": maximum height = ";
		std::cout << ans << endl;
	}
	return 0;
}