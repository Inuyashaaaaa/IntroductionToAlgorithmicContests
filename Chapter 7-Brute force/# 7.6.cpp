#include<bits/stdc++.h>
#define LL long long
using namespace std;
int pic[5][10];
int p[5][10]; 
bool vis[10];
bool read() {
	memset(pic, 0, sizeof(pic));
	memset(p, 0, sizeof(p));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			char ch;
			ch = cin.get();
			if (ch == '0') return false;
			if (isspace(ch)) {
				pic[i][j] = 0;
			}
			else if (ch == '_') {
				pic[i][j] = 1;
			}
			else if (ch == '|') {
				pic[i][j] = 2;
			}
			else {
				cin.get(); 
				break;
			}
		}
	}
	return true;
}

int offx[] = { 0, 1, 2 };
int offy[] = { 0, 1, 2 };
string s[3] = { "01010", "20002", "21012" };
vector<string> put(int num1) {
	int ox = num1 / 3;
	int oy = num1 % 3;
	vector<string> ss;
	ss.resize(5);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			ss[i].push_back(p[i + ox][j + oy * 2]);
			if (i == 0 && s[i][j] == '0') continue;
			p[i + ox][j + oy * 2] = s[i][j] - '0';
		}
	}
	return ss;
}

void reset(int num1, vector<string> ss) {
	int ox = num1 / 3;
	int oy = num1 % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 && s[i][j] == '0') continue;
			p[i + ox][j + oy * 2] = ss[i][j];
		}
	}
}

bool check() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (pic[i][j] != p[i][j]) return false;
		}
	}
	return true;
}

bool dfs(int d, int maxd) {
	if (check()) return true;
    if (d == maxd) return false;
	for (int i = 0; i < 9; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		vector<string> ss = put(i);
		if (dfs(d + 1, maxd))
			return true;
		reset(i, ss);
		vis[i] = false;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int kase = 0;
	while (read()) {
		cout << "Case " << ++kase << ": ";
		if (check() || dfs(0, 6)) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
	return 0;
}