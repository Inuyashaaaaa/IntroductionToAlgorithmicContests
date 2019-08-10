#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

int Lockid = 0;     //0表示没lock 正整数表示成功执行lock的程序
int var[26];

struct Program {
	int id;
	int line;       //行数
	int nowLine;    //当前行数
	string s[30];   //程序
};

deque<Program> waitQ;   //等待队列
queue<Program> blockQ;  //阻止队列

int main() {
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		if (kase++) {
			cout << endl;
		}
		// 数量 赋值语句 打印 LOCK UNLOCK END 时间
		memset(var, 0, sizeof(var));
		while (!blockQ.empty()) {
			blockQ.pop();
		}
		int t[6];
		int n, Q;
		cin >> n;
		for (int i = 1; i <= 5; i++) cin >> t[i];
		cin >> Q;

		//完成输入
		for (int i = 1; i <= n; i++) {
			Program p;
			string statement;
			int line = 0;
			p.id = i;
			p.nowLine = 0;
			while (cin >> statement) {
				string command;
				//赋值语句
				if (statement.length() == 1) {
					char ignoreCh;
					cin >> ignoreCh;
					int constValue;
					cin >> constValue;
					char buf[10];
					sprintf(buf, "1 %c %d", statement[0], constValue);
					command = buf;
				}
				else if (statement == "print") {
					char var;
					cin >> var;
					char buf[10];
					sprintf(buf, "2 %c", var);
					command = buf;
				}
				else if (statement == "lock") {
					command = "3";
				}
				else if (statement == "unlock") {
					command = "4";
				}
				else if (statement == "end") {
					command = "5";
				}
				//cout << command << endl;
				line++;
				p.s[line] = command;
				if (command == "5")
					break;
			}
			p.line = line;
			waitQ.push_back(p);
		}

		//处理

		while (!waitQ.empty()) {
			int time = Q;
			Program p;
			p = waitQ.front();
			waitQ.pop_front();
			bool flag = true;
			while (time > 0) {
				p.nowLine++;
				string s = p.s[p.nowLine];
				if (s[0] == '5') {
					break;
				}
				if (s[0] == '4') {
					Lockid = 0;
					if (!blockQ.empty()) {
						waitQ.push_front(blockQ.front());
						blockQ.pop();
					}
					time -= t[4];
				}
				if (s[0] == '3') {
					if (Lockid == 0)
					{
						Lockid = p.id;
						time -= t[3];
					}
					else {
						p.nowLine--; //没执行成功
						blockQ.push(p);
						flag = false;
						break;
					}
				}
				if (s[0] == '2') {
					time -= t[2];
					cout << p.id << ": " << var[s[2] - 'a'] << endl;
				}
				if (s[0] == '1') {
					time -= t[1];
					stringstream ss(s);
					int ignoreInt, needInt;
					char ch;
					ss >> ignoreInt >> ch >> needInt;
					var[ch - 'a'] = needInt;
				}
			}
			if (p.nowLine != p.line && flag) {
				waitQ.push_back(p);
			}
		}

	}
}