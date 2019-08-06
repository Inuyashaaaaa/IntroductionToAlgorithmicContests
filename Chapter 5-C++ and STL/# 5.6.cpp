#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 1050;

struct Point {
	double x, y;
	friend bool operator < (Point& p1, Point& p2) {
		return p1.x < p2.x;
	}
}p[maxn];

bool isFind(int i, double& mx, int& n) {
	for (int j = 0; j < n; j++) {
		if (p[i].y == p[j].y && p[i].x + p[j].x == 2 * mx)
			return true;
	}
	return false;
}

int main() {
	int T;
	// freopen("5-6.in", "r", stdin);
	// freopen("5-6.out", "w", stdout);
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		sort(p, p + n);
		double midx;
		if (n % 2 == 0)
			midx = (p[n / 2 - 1].x + p[n / 2].x) / 2;
		else
			midx = p[n / 2].x;
		bool judge = true;
		for (int i = 0; i < n; i++) {
			if (!isFind(i, midx, n)) {
				judge = false;
				break;
			}
		}
		if (judge) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	//system("pause");
	return 0;
}