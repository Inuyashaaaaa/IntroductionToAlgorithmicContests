#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<set>
using namespace std;
// 文章顺序 0,1,2,3 对应映射 字符串和行
vector<map<string, vector<int>>> vec0;
// 文章顺序 0,1,2,3 对应行字符串 (供第一个使用)
vector<vector<string>> vec1;

int main() {
	int T;
	cin >> T;
    ios::sync_with_stdio(false);
	//吃掉换行
	cin.get();
	for (int i = 0; i < T; i++) {
		string s;
		map<string, vector<int>> Map;
		vector<string> vec;
		int cnt = 0;
		while (getline(cin, s) && s != "**********") {
			vec.push_back(s);
			for (int i = 0; i < s.length(); i++) {
				if (!isalpha(s[i]))
					s[i] = ' ';
			}
			stringstream ss(s);
			string word;
			while (ss >> word) {
				for (char& ch : word) {
					ch = tolower(ch);
				}
				Map[word].push_back(cnt);
			}
			cnt++;
		}
		vec0.push_back(Map);
		vec1.push_back(vec);
	}
	cin >> T;
	//吃掉换行
	cin.get();
	while (T--) {
		string s;
		getline(cin, s);
		int k;
		if ((k = s.find("AND")) != string::npos) {
			string key1 = s.substr(0, k - 1);
			string key2 = s.substr(k + 4);
			int cnt = 0;
			bool first = true;
			for (auto& map1 : vec0) {
				set<int> rows;
				bool isFind1 = map1.count(key1);
				bool isFind2 = map1.count(key2);
				if (isFind1 && isFind2) {
					if (!first)
						cout << "----------" << endl;
					for (auto& row : map1[key1]) {
						rows.insert(row);
					}
					for (auto& row : map1[key2]) {
						rows.insert(row);
					}
					first = false;
				}
				for (auto& row : rows) {
					cout << vec1[cnt][row] << endl;

				}
				cnt++;
			}
			if (first) {
				cout << "Sorry, I found nothing." << endl;
			}
		}
		else if ((k = s.find("OR")) != string::npos) {
			string key1 = s.substr(0, k - 1);
			string key2 = s.substr(k + 3);
			int cnt = 0;
			bool first = true;
			for (auto& map1 : vec0) {
				set<int> rows;
				bool isFind1 = map1.count(key1);
				bool isFind2 = map1.count(key2);
				if (isFind1 || isFind2) {
					if (!first)
						cout << "----------" << endl;
					if (isFind1) {
						for (auto& row : map1[key1]) {
							rows.insert(row);
						}
					}
					if (isFind2) {
						for (auto& row : map1[key2]) {
							rows.insert(row);
						}
					}
					first = false;
				}
				for (auto& row : rows) {
					cout << vec1[cnt][row] << endl;

				}
				cnt++;
			}
			if (first) {
				cout << "Sorry, I found nothing." << endl;
			}
		}
		else if ((k = s.find("NOT")) != string::npos) {
			string key = s.substr(4);
			int cnt = 0;
			bool first = true;
			for (auto& map1 : vec0) {
				set<int> rows;
				bool isFind1 = map1.count(key);
				if (!isFind1) {
					if (!first)
						cout << "----------" << endl;
					for (auto string : vec1[cnt]) {
						cout << string << endl;
					}
					first = false;
				}
				cnt++;
			}
			if (first) {
				cout << "Sorry, I found nothing." << endl;
			}
		}
		else {
			string key = s;
			int cnt = 0;
			bool first = true;
			for (auto& map1 : vec0) {
				set<int> rows;
				bool isFind = map1.count(key);
				if (isFind) {
					if (!first)
						cout << "----------" << endl;
					for (auto& row : map1[key]) {
						rows.insert(row);
					}
					first = false;
				}
				for (auto& row : rows) {
					cout << vec1[cnt][row] << endl;
				}
				cnt++;
			}
			if (first) {
				cout << "Sorry, I found nothing." << endl;
			}
		}
		cout << "==========" << endl;
	}
	return 0;
}


