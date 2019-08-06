#include<set>
#include<string>
#include<iostream>
using namespace std;

set<string> word;
int main() {
	string s;
	while (cin >> s) {
		word.insert(s);
	}

	for (auto iter = word.begin(); iter != word.end(); iter++) {
		int len = iter->length();
		for (int i = 1; i < len; i++) {
			string head = (*iter).substr(0, i);
			string tail = (*iter).substr(i);
			if (word.count(head) && word.count(tail)) {
				cout << (*iter) << endl;
				break;
			}
		}
	}
	return 0;
}