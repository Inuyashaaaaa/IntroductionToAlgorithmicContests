//UVa 1411 蚂蚁
//递归与分治

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;

int nowX, nowY;

struct Node {
	bool type; // if type == 0 means ant else means apple
	int x, y;  // which means coordinate
	int id;
	int part;
}node[maxn * 2];

//保证是左下角的那个点
bool cmp1(Node& n1, Node& n2) {
	return n1.y != n2.y ? n1.y < n2.y : n1.x < n2.x;
}

//保证是从度数小的到大的
bool cmp2(Node& n1, Node& n2) {
	return atan2(n1.y - nowY, n1.x - nowX) < atan2(n2.y - nowY, n2.x - nowX);
}

bool cmp3(Node& n1, Node& n2) {
	if (n1.type == n2.type)
		return n1.id < n2.id;
	else if (n1.type == 0)
		return 1;
	return 0;
}

//[left, right)
void solve(int left, int right) {
	if (left >= right) return;
	sort(node + left, node + right, cmp1);
	//取出左下角的那个点点
	Node n = node[left];
	nowX = n.x; nowY = n.y;
	sort(node + left + 1, node + right, cmp2);
	int type1 = 0; //ant
	int type2 = 0; //apple
	int pos;
	for (pos = left; pos < right; pos++) {
		if (node[pos].type == 0) {
			type1++;
		}
		else {
			type2++;
		}
		if (type1 == type2) break;
	}
	node[left].part = node[pos].id;
	node[pos].part = n.id;
	solve(left + 1, pos);
	solve(pos + 1, right);
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
    int kase = 0;
	while(cin >> n) {
        if(kase++)
        cout << endl;
        for (int i = 0; i < 2 * n; i++) {
            if (i < n) node[i].type = 0;
            else node[i].type = 1;
            node[i].id = i >= n ? i - n + 1 : i + 1;
            cin >> node[i].x >> node[i].y;
        }
        solve(0, 2 * n);
        sort(node, node + 2 * n, cmp3);
        for (int i = 0; i < n; i++) {
            cout << node[i].part << endl;
        }
    }
	return 0;
}