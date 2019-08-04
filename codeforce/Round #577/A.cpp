#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
vector<string> vec1;
vector<int> vec2;
map<char, int> Map;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vec1.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		vec2.push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		Map['A'] = 0;
		Map['B'] = 0;
		Map['C'] = 0;
		Map['D'] = 0;
		Map['E'] = 0;
		for (int j = 0; j < n; j++) {
			char ch = vec1[j][i];
			Map[ch] ++;
		}
		int maxN = Map['A'];
		maxN = max(maxN, Map['B']);
		maxN = max(maxN, Map['C']);
		maxN = max(maxN, Map['D']);
		maxN = max(maxN, Map['E']);
		ans += maxN * vec2[i];
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}