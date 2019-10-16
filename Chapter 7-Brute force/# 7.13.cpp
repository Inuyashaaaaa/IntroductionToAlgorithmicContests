#include<bits/stdc++.h>
using namespace std;
string s;
string symbol = " *+-";
int len;
string sym; //记录符号
vector<int> num;
vector<char> symboll;

const int maxn = 9 + 3;

bool cal() {
	int size = num.size();
	for (int i = 0; i < size - 1; i++) {
		if (symboll[i] == '*') {
			num[i + 1] = num[i] * num[i + 1];
			num[i] = -1;
			symboll[i] = ' ';
		}
	}
	vector<int> num1;
	vector<char> symbol2;
	for (int i = 0; i < size; i++) {
		if (i && symboll[i - 1] != ' ') symbol2.push_back(symboll[i - 1]);
		if (num[i] != -1) num1.push_back(num[i]);
	}
	size = num1.size();
	int e = num1[0];
	if (size == 2 && num1[0] == 2100 && num1[1] == 100) {
		int k = 1;
	}
	for (int i = 1; i < size; i++) {
		if (symbol2[i - 1] == '+') e += num1[i];
		else e -= num1[i];
	}
	//cout << " " << e;
	//cout << endl;
	return e == 2000;
}

bool check() {
	num.clear();
	symboll.clear();
	int e = 0;
	for (int i = 0; i < len; i++) {
		e *= 10;
		e += s[i] - '0';
		if (sym[i] != ' ') {
			num.push_back(e);
			e = 0;
			symboll.push_back(sym[i]);
		}
	}

	int cnt = 0;
	for (auto n : num) {
		if (n == 0) {
			cnt++;
			continue;
		}
		while (n) {
			n /= 10;
			cnt++;
		}
	}
	/*
	for (auto& n : num) {
		cout << n << " ";
	}
	for (auto& ch : symboll) {
		cout << ch << " ";
	}
	cout << endl;
	*/
	if (cnt != len) return false;
	return cal();
}

void print() {
	cout << "  ";
	for (int i = 0; i < len; i++) {
		cout << s[i];
		if (sym[i] != ' ' && i != len - 1) cout << sym[i];
	}
	cout << "=" << endl;
}

bool dfs(int d) {
	if (d == len - 1) {
		if (check()) {
			print();
			return true;
		}
		return false;
	}
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		sym[d] = symbol[i];
		if (dfs(d + 1)) flag = true;
	}
	return flag;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int kase = 0;
	while (cin >> s) {
		if (s == "=") break;
		cout << "Problem " << ++kase << endl;
		if (s == "2000=") {
			cout << "  IMPOSSIBLE" << endl;
			continue;
		}
		len = s.length() - 1;
		sym.resize(maxn);
		if (!dfs(0)) {
			cout << "  IMPOSSIBLE" << endl;
		}
	}
}
