#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#define maxn 50
#define INF 1e6
using namespace std;

int map[maxn][maxn];
int n, m;
int water;
double Num;

bool judge(double height)
{
	Num = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] < height)
			{
				sum += height - map[i][j];
				Num++;
			}
		}
	}
	if (sum * 100 > water)
		return true; //海拔定高了 海拔要小一点
	return false;//海拔定低了 海拔要大一点
}

int main()
{
//	freopen("4-10.in","r",stdin);
//	freopen("4-10.out","w",stdout);
	int cnt = 0;
	while (cin >> n >> m && n && m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		cin >> water;
		double max = INF;
		double min = -INF;
		while (fabs(max - min) > 1e-6)
		{
			double mid = (min + max) / 2;
			if (judge(mid))
				max = mid;
			else
				min = mid;
		}
		cout << "Region " << ++cnt << endl;
		cout << "Water level is " << fixed << setprecision(2) << min << " meters." << endl;
		cout << (Num / (n*m) * 100) << " percent of the region is under water." << endl;
		cout << endl;
	}
	return 0;
}


