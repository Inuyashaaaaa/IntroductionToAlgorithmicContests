#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;
vector<vector<string>> vec;
int maxLen[10000] = { 0 };

int main() {
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<string> temp;
		int cnt = 0;
		while (ss >> s) {
			if (s.length() > maxLen[cnt]) 
				maxLen[cnt] = s.length();
			cnt++;
			temp.push_back(s);
		}
		vec.push_back(temp);
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (j != vec[i].size() - 1)
				cout << left << setw(maxLen[j] + 1) << vec[i][j];
			else
				cout << vec[i][j];
		}
		cout << endl;
	}
	return 0;
}

