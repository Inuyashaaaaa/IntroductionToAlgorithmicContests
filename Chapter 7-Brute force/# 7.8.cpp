#include<bits/stdc++.h>
#define LL long long
using namespace std;
string s[3];
char ch[] = "*0123456789";
int len[3];

bool cal() {
	int num1, num2, num3;
	num1 = stoi(s[0]);
	num2 = stoi(s[1]);
	num3 = num1 * num2;
	char buf[10];
	sprintf(buf, "%d", num3);
	string ss = buf;
	if (ss.length() != len[2]) return false;
	for (int i = 0; i < len[2]; i++) {
		if (s[2][i] != ss[i] && s[2][i] != '*') {
			return false;
		}
	}
	return true;
}

int check(int id, int pos) {
	if (id == 2) return cal();
	int cnt = 0;
	char store = s[id][pos];
	int ta, tb;
	if (len[id] == pos + 1) {
		ta = id + 1;
		tb = 0;
	}
	else {
		ta = id;
		tb = pos + 1;
	}
	if (isdigit(store)) {
		cnt += check(ta, tb);
	}
	else {
		for (int i = 1; i < 11; i++) {
			if (i == 1 && pos == 0) continue;
			s[id][pos] = ch[i];
			cnt += check(ta, tb);
			if (cnt > 1) break;
		}
	}
	s[id][pos] = store;
	return cnt;
}

//修改原先的字符串
//d代表当前深度 maxd代表搜索到的深度 id代表是哪一个字符串
//一共有三个字符串 s[0] * s[1] = s[2
//pos代表某个字符串的位置
bool dfs(int d, int maxd, int id, int pos) {
	if (d == maxd) {
		return check(0, 0) == 1;
	}
	if (id == 3) return false;
	//保留原先字符
	char store = s[id][pos];
	int ta, tb;
	if (len[id] == pos + 1) {
		ta = id + 1;
		tb = 0;
	}
	else {
		ta = id;
		tb = pos + 1;
	}

	for (int i = 0; i < 11; i++) {
		//除去前导零
		if (i == 1 && pos == 0) continue;
		//如果一样的话 没必要替换
		if (s[id][pos] == ch[i]) {
			if (dfs(d, maxd, ta, tb)) return true;
		}
		else {
			s[id][pos] = ch[i];
			if (dfs(d + 1, maxd, ta, tb)) return true;
			//回溯
			s[id][pos] = store;
		}
	}
	return false;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int kase = 0;
    //Case 1: 
	while (cin >> s[0]) {
		if (s[0][0] == '0') break;
        cout << "Case " << ++kase << ": ";
		cin >> s[1] >> s[2];
		len[0] = s[0].length();
		len[1] = s[1].length();
		len[2] = s[2].length();
		int maxd;
		for (maxd = 0; ; maxd++) {
			if (dfs(0, maxd, 0, 0)) break;
		}
		cout << s[0] << " " << s[1] << " " << s[2] << endl;
	}
	return 0;
}