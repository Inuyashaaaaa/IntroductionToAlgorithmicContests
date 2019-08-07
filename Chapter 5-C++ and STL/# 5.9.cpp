#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<string>
#include<map>
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

map<string, int> Map;
map<char, int> topMap;

// 获取深度
int getDepth(string& s) {
	int cnt = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ']')
			cnt++;
		else
			break;
	}
	return cnt;
}

// 赋值语句 右边的值 返回false代表 BUG了
bool AssignmentRight(string &s, int& v) {
	int depth = getDepth(s);
	if (depth == 0)
	{
		v = stoi(s);
		return true;
	}
	stringstream ss(s);
	stack<char> s1;
	char ch;
	int cnt = 0;
	int value;
	while (ss >> ch) {
		if (ch == '[')
			cnt++;
		if (cnt == depth) {
			ss >> value;
			break;
		}
		s1.push(ch);
	}

	while (!s1.empty()) {
		ch = s1.top();
		s1.pop();
		string statement;
		char buf[100];
		if (value >= topMap[ch])
			return false;
		sprintf(buf, "%c[%d]", ch, value);
		statement = buf;
		if (!Map.count(statement))
			return false;
		value = Map[statement];
		if (!s1.empty())
			s1.pop();
	}

	v = value;
	return true;
}

// 赋值语句 左边的值 返回false代表 BUG了  isDefine 表示是不是定义
bool AssignmentLeft(string &s, string& v, bool isDefine) {
	int depth = getDepth(s);
	stringstream ss(s);
	stack<char> s1;
	char ch;
	int cnt = 0;
	int value;
	while (ss >> ch) {
		if (ch == '[')
			cnt++;
		if (cnt == depth) {
			ss >> value;
			break;
		}
		s1.push(ch);
	}
	// a
	while (s1.size() != 1) {
		ch = s1.top();
		s1.pop();
		string statement;
		char buf[100];
		if (!isDefine && value >= topMap[ch])
			return false;
		sprintf(buf, "%c[%d]", ch, value);
		statement = buf;
		if (!Map.count(statement))
			return false;
		value = Map[statement];
		s1.pop();
	}
	char buf[100];
	ch = s1.top();
	s1.pop();
	if (value >= topMap[ch] && !isDefine)
		return false;
	sprintf(buf, "%c[%d]", ch, value);
	v = buf;
	return true;
}

// 定义语句
bool defineStatement(string &s) {
	string v;
	if (AssignmentLeft(s, v, true)) {
		stringstream ss(s);
		char ch1;
		char ch2;
		int value;
		ss >> ch1;
		ss >> ch2;
		ss >> value;
		topMap[ch1] = value;
		return true;
	}
	else {
		return false;
	}
}

// 判断是赋值还是定义语句 并执行
bool process(string &s) {
	int k = s.find('=');
	if (k == string::npos) {
		if (!defineStatement(s))
			return false;
	}
	else {
		string left = s.substr(0, k);
		string right = s.substr(k + 1);
		string v;
		int value;
		if (AssignmentLeft(left, v, false)) {
			if (AssignmentRight(right, value)) {
				Map[v] = value;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
    //freopen("5-9.in", "r", stdin);
    //freopen("5-9.out", "w", stdout);
	string s;
	int value;
	string v;
	int cnt;
	while (cin >> s && s != ".") {
		topMap.clear();
		Map.clear();
		bool first = true;
		int index = 0;
		cnt = 1;
		if (!process(s) && first) {
			first = false;
			index = cnt;
		}
		cnt++;
		while (cin >> s && s != ".") {
			if (!process(s) && first) {
				first = false;
				index = cnt;
			}
			cnt++;
		}
		cout << index << endl;
	}

	//system("pause");
	return 0;
}