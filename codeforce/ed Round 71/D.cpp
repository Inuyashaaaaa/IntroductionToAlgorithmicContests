#include<bits/stdc++.h>
#define LL long long
using namespace std;


const int maxn = 3e5 + 10;
const LL Mod = 998244353;


struct Point {
	int x, y;
	friend istream& operator >> (istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
};
Point p[maxn];

bool cmp1(Point& p1, Point& p2) {
	return p1.x < p2.x;
}

bool cmp2(Point& p1, Point& p2) {
	return p1.y < p2.y;
}

bool cmp3(Point& p1, Point& p2) {
	if (p1.x != p2.x) return p1.x < p2.x;
	return p1.y < p2.y;
}

//Ann
LL A(LL n) {
	if (n == 1)
		return 1;
	return (A(n - 1) * n) % (2 * Mod);
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	LL n;
	cin >> n;

	for (LL i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n, cmp1);
	int cnt = 0;
	LL xUp = 1;
	for (int i = 0; i < n - 1; i++) {
		if (p[i].x == p[i + 1].x) {
			cnt++;
		}
		else {
			xUp *= A(cnt + 1);
			xUp %= Mod;
			cnt = 0;
		}
	}
	if (cnt) {
		xUp *= A(cnt + 1);
		xUp %= Mod;
		cnt = 0;
	}
	sort(p, p + n, cmp2);
	LL yUp = 1;
	for (int i = 0; i < n - 1; i++) {
		if (p[i].y == p[i + 1].y) {
			cnt++;
		}
		else {
			yUp *= A(cnt + 1);
			yUp %= Mod;
			cnt = 0;
		}
	}
	if (cnt) {
		yUp *= A(cnt + 1);
		yUp %= Mod;
		cnt = 0;
	}
	cnt = 0;
	sort(p, p + n, cmp3);
	LL xyUp = 0;
	bool flag = true;
	for (int i = 0; i < n - 1; i++) {
		if (p[i].y > p[i + 1].y) {
			flag = false;
			break;
		}
	}
	if (flag) {
		xyUp = 1;
		for (int i = 0; i < n - 1; i++) {
			if (p[i].x == p[i + 1].x &&
				p[i].y == p[i + 1].y) {
				cnt++;
			}
			else {
				xyUp *= A(cnt + 1);
				xyUp %= Mod;
				cnt = 0;
			}
		}
	}
	if (cnt) {
		xyUp *= A(cnt + 1);
		xyUp %= Mod;
		cnt = 0;
	}
	cout << (A(n) - xUp - yUp + xyUp + 2 * Mod) % Mod << endl;
	return 0;
}
