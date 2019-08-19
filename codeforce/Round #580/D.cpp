#include<iostream>
#include<vector>
using namespace std;
#define INF 0x7fffffff

const int mask = 1;

class UnionFind {
private:
	vector<int> parent;
	vector<int> sz;
public:
	UnionFind(int size)
	{
		parent.resize(size);
		sz.resize(size);

		for (int i = 0; i < size; i++)
		{
			parent[i] = i;
			sz[i] = 1;
		}
	}

	int getSize(int i)
	{
		return sz[find(i)];
	}

	int find(int p)
	{
		while (p != parent[p])
		{
			p = parent[p];
		}
		return p;
	}


	bool isConnected(int p, int q)
	{
		return find(p) == find(q);
	}

	void unionElements(int p, int q)
	{

		int pRoot = find(p);
		int qRoot = find(q);

		if (pRoot == qRoot)
			return;

		if (sz[pRoot] < sz[qRoot])
		{
			parent[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else
		{
			parent[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
		}

	}
};


const int maxn = 1e4 + 40;
int a[maxn][65];
UnionFind u(maxn);


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned long long x;
		cin >> x;
		//cout << x << endl;
		for (int j = 0; j < 64; j++) {
			if (x & mask) {
				a[i][j] = 1;
			}
			else a[i][j] = 0;
			x >>= 1;
			cout << a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < 64; i++) {
		bool first = true;
		int p;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 1 && first)
			{
				p = j;
				first = false;
			}
			if (a[j][i] == 1 && !first)
				u.unionElements(p, j);

		}
	}
	int size = INF;
	for (int i = 0; i < n; i++) {
		int s = u.getSize(i);
		if (s < size && s != 1) {
			size = s;
		}
	}
	cout << (size == INF ? -1 : size == 2 ? 3 : size) << endl;
	system("pause");
	return 0;
}