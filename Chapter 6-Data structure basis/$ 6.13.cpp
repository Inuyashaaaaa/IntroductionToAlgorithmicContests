#include<iostream>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;
const int maxn = 200 + 10;
int pic[maxn][maxn];
bool allReturn = false;
int n, m;
int cnt;
int a[200];

const char* numArray[] = { "0000", "0001","0010","0011","0100",
"0101","0110","0111","1000", "1001"};
const char* alphaArray[] = { "1010", "1011","1100","1101","1110"
,"1111" };
void dfs1(int, int);
void dfs2(int, int);

//填充边 识别图形的边缘
void dfs1(int r, int c) {
	if (r < 0 || r > n + 1 || c < 0 || c > 4 * m + 7 || pic[r][c] >= 2 || pic[r][c] == -1)
		return;
	if (pic[r][c] == 1) {
		dfs2(r, c);
		cnt++;
	}
	else if (pic[r][c] == 0)
	{
		pic[r][c] = -1;
		dfs1(r + 1, c);
		dfs1(r - 1, c);
		dfs1(r, c + 1);
		dfs1(r, c - 1);
	}
}

void dfs2(int r, int c) {
	if (r < 0 || r > n + 1 || c < 0 || c > 4 * m + 7 || pic[r][c] != 1)
		return;
	if (!pic[r][c]) return;
	pic[r][c] = cnt;
	dfs2(r + 1, c);
	dfs2(r - 1, c);
	dfs2(r, c + 1);
	dfs2(r, c - 1);
}

void dfs3(int r, int c) {
	if (r < 0 || r > n + 1 || c < 0 || c > 4 * m + 7 || pic[r][c] == 1)
		return;
	if (pic[r][c] >= 2 && !allReturn) return;
	if (pic[r][c] >= 2 && allReturn) {
		allReturn = false;
		a[pic[r][c]]++;
		return;
	}
	pic[r][c] = 1;
	dfs3(r + 1, c);
	dfs3(r - 1, c);
	dfs3(r, c + 1);
	dfs3(r, c - 1);
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int kase = 0;
	while (cin >> n >> m && n) {
		cout << "Case " << ++kase << ": ";
		memset(a, 0, sizeof(a));
		memset(pic, 0, sizeof(pic));
		cnt = 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char ch;
				cin >> ch;
				if (isalpha(ch)) {
					ch -= 'a';
					pic[i][j * 4] = alphaArray[ch][0] - '0';
					pic[i][j * 4 + 1] = alphaArray[ch][1] - '0';
					pic[i][j * 4 + 2] = alphaArray[ch][2] - '0';
					pic[i][j * 4 + 3] = alphaArray[ch][3] - '0';
				}
				else {
					ch -= '0';
					pic[i][j * 4] = numArray[ch][0] - '0';
					pic[i][j * 4 + 1] = numArray[ch][1] - '0';
					pic[i][j * 4 + 2] = numArray[ch][2] - '0';
					pic[i][j * 4 + 3] = numArray[ch][3] - '0';
				}
			}
		}
		dfs1(0, 0);

		for (int i = 1; i <= n; i++) {
			for (int j = 4; j <= 4 * m + 3; j++) {
				if (pic[i][j] == 0) {
					allReturn = true;
					dfs3(i, j);
				}
			}
		}
		int Cnt[6] = { 0 };
		for (int i = 2; i < cnt; i++) {
			Cnt[a[i]]++;
		}
		for (int i = 0; i < Cnt[1]; i++)cout << 'A';
		for (int i = 0; i < Cnt[5]; i++)cout << 'D';
		for (int i = 0; i < Cnt[3]; i++)cout << 'J';
		for (int i = 0; i < Cnt[2]; i++)cout << 'K';
		for (int i = 0; i < Cnt[4]; i++)cout << 'S';
		for (int i = 0; i < Cnt[0]; i++)cout << 'W';
		cout << endl;
	}

	return 0;
}