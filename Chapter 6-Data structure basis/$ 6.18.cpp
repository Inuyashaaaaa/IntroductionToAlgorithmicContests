#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
const int maxc = 1000 + 30;
int nx, ny, nz, n;
int x[maxn], y[maxn], z[maxn];
int x0[maxn], Y0[maxn], z0[maxn];
int xs[maxn], ys[maxn], zs[maxn];
int color[maxn][maxn][maxn];


//三维图形的六个可移动方向
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

struct cell {
	int xId, yId, zId;
	cell(int x, int y, int z) :xId(x), yId(y), zId(z) {};
};

int getVolume(int xId, int yId, int zId) {
	return (xs[xId + 1] - xs[xId]) * (ys[yId + 1] - ys[yId]) *
		(zs[zId + 1] - zs[zId]);
}

int getArea(int xId, int yId, int zId, int direction) {
	if (dx[direction] != 0) return (ys[yId + 1] - ys[yId]) * (zs[zId + 1] - zs[zId]);
	if (dy[direction] != 0) return (zs[zId + 1] - zs[zId]) * (xs[xId + 1] - xs[xId]);
	if (dz[direction] != 0) return (xs[xId + 1] - xs[xId]) * (ys[yId + 1] - ys[yId]);
}

//

/*离散化*/
void discretization(int* a, int& n) {
	sort(a, a + n);
	n = unique(a, a + n) - a;
}

int getId(int* a, int n, int k) {
	return lower_bound(a, a + n, k) - a;
}

/*种子填充*/
void floodfill(int& v, int& s) {
	queue<cell> q;
	q.push(cell(0, 0, 0));
	//标记走过
	color[0][0][0] = 2;
	while (!q.empty()) {
		cell c = q.front();
		q.pop();
		int div = getVolume(c.xId, c.yId, c.zId);
		v += getVolume(c.xId, c.yId, c.zId);
		for (int i = 0; i < 6; i++) {
			cell c2(c.xId + dx[i], c.yId + dy[i], c.zId + dz[i]);
			if (c2.xId < 0 || c2.xId > nx - 2 || c2.yId < 0 ||
				c2.yId > ny - 2 || c2.zId < 0 || c2.zId > nz - 2)
				continue;
			if (color[c2.xId][c2.yId][c2.zId] == 1) {
				s += getArea(c2.xId, c2.yId, c2.zId, i);
			}
			else if (!color[c2.xId][c2.yId][c2.zId]) {
				color[c2.xId][c2.yId][c2.zId] = 2;
				q.push(c2);
			}
		}
	}
	int k = v;
	v = maxc * maxc * maxc - v;
}


int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {

		cin >> n;
		//围空气
		xs[0] = ys[0] = zs[0] = 0;
		xs[1] = ys[1] = zs[1] = maxc;
		nx = ny = nz = 2;
		//离散化
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i] >> z[i];
			cin >> x0[i] >> Y0[i] >> z0[i];
			xs[nx++] = x[i];
			xs[nx++] = x[i] + x0[i];
			ys[ny++] = y[i];
			ys[ny++] = y[i] + Y0[i];
			zs[nz++] = z[i];
			zs[nz++] = z[i] + z0[i];
		}
		discretization(xs, nx);
		discretization(ys, ny);
		discretization(zs, nz);
		//转ID， 找被围区域
		std::memset(color, 0, sizeof(color));
		for (int i = 0; i < n; i++) {
			int xIdF = getId(xs, nx, x[i]);
			int xIdE = getId(xs, nx, x[i] + x0[i]);
			int yIdF = getId(ys, ny, y[i]);
			int yIdE = getId(ys, ny, y[i] + Y0[i]);
			int zIdF = getId(zs, nz, z[i]);
			int zIdE = getId(zs, nz, z[i] + z0[i]);
			for (int x = xIdF; x < xIdE; x++) {
				for (int y = yIdF; y < yIdE; y++) {
					for (int z = zIdF; z < zIdE; z++) {
						color[x][y][z] = 1;
					}
				}
			}
		}
		int v = 0;
		int s = 0;
		floodfill(v, s);
		cout << s << " " << v << endl;
	}
}