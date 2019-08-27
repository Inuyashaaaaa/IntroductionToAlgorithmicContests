#include<bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;

	int kase = 0;
	while (cin >> T && T) {
		cout << "S-Tree #" << ++kase << ":" << endl;
		cin.get();
		string s;
		getline(cin, s);
		stringstream ss(s);
		int cnt = 0;
		char ch;
		int x;
		int weight[10];
		while (ss >> ch >> x) {
			//cout << ch << " " << x << endl;
			cnt++;
			weight[x] = cnt;

		}
		string index;
		cin >> index;
		int n;
		cin >> n;
		while (n--) {
			string sss;
			cin >> sss;
			int ans = 0;
			for (int i = 0; i < sss.size(); i++) {
				ans += sss[i] == '0' ? 0 : pow(2, (cnt - weight[i+1]));
			}
			cout << index[ans];
		}
		cout << endl;
		cout << endl;
	}
}