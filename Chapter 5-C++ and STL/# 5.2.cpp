#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

map<vector<int>, int> Map;

int main() {
	int T;
	cin >> T;
	while (T--) {
		Map.clear();
		int n;
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		bool judge = true; // true 表示 0  false 表示 loop
		for (int i = 0; i < 1000; i++) {
			for (const int& x : vec) {
				if (x != 0)
					judge = false;
			}
			if (judge)
				break;
			if (Map.count(vec)) {
				judge = false;
				break;
			}
			Map[vec] = 1;
			int nTemp = vec[0];
			for (int i = 0; i < n - 1; i++) {
				vec[i] = abs(vec[i] - vec[i + 1]);
			}
			vec[n - 1] = abs(vec[n - 1] - nTemp);
			judge = true;
		}
		if (judge)
			cout << "ZERO" << endl;
		else
			cout << "LOOP" << endl;
	}

	return 0;
}

