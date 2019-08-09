#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int INF = 0x7fffffff;

int a[10] = { 1, 10, 5, 10, 5, 2, 5, 10, 5, 10 };

int map[100][100];

int main() {

	string s;
	cin >> s;
	int len = s.length();
	int i = 0;
	int minn = min(1024, len / 2);
	for (i = 1; i < minn; i++) {
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, i);
		if (s1 == s2) {
			s = s.substr(0, i);
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i > j)
				continue;
			int ans = 0;
			bool judge = false;
			for (int t = 1; t < s.length(); t++) {
				int minn = INF;
				for (int k = 0; k < a[i]; k++) {
					for (int l = 0; l < a[j]; l++) {
						if (k == 0 && l == 0)
							continue;
						int e = (i * k + j * l + s[t - 1] - '0') % 10;
						if (e + '0' == s[t]) {
							judge = true;
							if (k + l - 1 < minn) {
								minn = k + l - 1;
							}
						}
					}
				}
				if (judge)
					ans += minn;
				else
					break;
			}
			if (judge)
				map[i][j] = ans;
			else
				map[i][j] = -1;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < j)
				cout << map[i][j];
			else
				cout << map[j][i];
			cout << " ";
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}