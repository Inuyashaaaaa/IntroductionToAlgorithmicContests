#include<bits/stdc++.h>
using namespace std;

const int maxn = 64;
char pic[maxn][maxn];
vector<int> ans;
int kase = 0;

string tenToFive(int x) {
	string ret;
	while (x) {
		ret += x % 5 + '0';
		x /= 5;
	}
	return ret; //倒着的
}

void transformToPic(int n) {
	cout << "Image " << ++kase << endl;
	memset(pic, '.', sizeof(pic));
	vector<int> data;
	int x;
	while (cin >> x && x != -1)
		data.push_back(x);
	for (auto& num : data) {
		string s = tenToFive(num);
		int left, top, width;
		left = top = 0;
		width = n;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '2' || s[i] == '4') top += width / 2;
			if (s[i] == '3' || s[i] == '4') left += width / 2;
			width /= 2;
		}
		for (int i = left; i < left + width; i++) 
			for (int j = top; j < top + width; j++) 
				pic[i][j] = '*';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << pic[i][j];	
		    cout << endl;
	}
}

int fiveToTen(string dir) {
	int ret = 0;
	int len = dir.size();
	for (int i = 0; i < len; i++) 
		ret += (dir[i] - '0') * pow(5, i);
	return ret;
}

void dfs(int left, int top, int width, string dir) {
	bool Bflag = true;  //全黑
	bool Wflag = true;  //全白
	for (int i = left; i < width + left; i++) {
		for (int j = top; j < width + top; j++) {
			if (pic[i][j] == '0') Bflag = false;
			if (pic[i][j] == '1') Wflag = false;
			if (!Wflag && !Bflag) break;
		}
	}
	if (Bflag) 
		ans.push_back(fiveToTen(dir));
	if (Wflag || Bflag) return;
	dfs(left, top, width / 2, dir + "1");
	dfs(left, top + width / 2, width / 2, dir + "2");
	dfs(left + width / 2, top, width / 2, dir + "3");
	dfs(left + width / 2, top + width / 2, width / 2, dir + "4");
}

void transformToNode(int n) {
	ans.clear();
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> pic[i][j];
	dfs(0, 0, n, "");
	sort(ans.begin(), ans.end());
	cout << "Image " << ++kase;
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		if (i % 12 == 0) cout << endl << ans[i];
		else cout << " " << ans[i];
	}
	cout << endl;
	cout << "Total number of black nodes = " << size << endl;
}

int main() {
	int n;
	while (cin >> n && n) {
		if (kase) cout << endl;
		if (n < 0) transformToPic(-n);	
		else transformToNode(n);
	}
	return 0;
}