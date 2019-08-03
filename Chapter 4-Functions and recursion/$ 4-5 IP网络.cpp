#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

int map[1010][40];
int find1[40];

//分别表示 第几个 数字是啥 四个数字的哪一个
void store(int i, int num, int index)
{
	int first = index * 8;
	for (int k = first; k > first - 8; k--)
	{
		map[i][k] = num % 2;
		num /= 2;
	}
}

int main()
{
//	freopen("4-5.in","r",stdin);
//	freopen("4-5.out","w",stdout);
	int T;
	while(cin >> T)
	{			
		for(int i=1;i<=T;i++)
		{
			char s[20];
			cin >> s;
			int a[4];
			sscanf(s, "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
			for (int j = 1; j <= 4; j++)
				store(i, a[j - 1], j);
			//for (int j = 1; j <= 32; j++)
			//	cout << map[i][j];
		}
		memset(find1, 1, sizeof(find1));
		for (int i = 1; i <= 32; i++)
		{
			for (int j = 2; j <= T; j++)
			{
				if (map[j][i] != map[j-1][i])
				{
					find1[i] = 0;
					break;
				}
			}
		}
		int judge = 1;
		//最小网络地址
		int a[4] = { 0 };
		for (int i = 1; i <= 32; i++)
		{
			a[(i - 1) / 8] *= 2;
			if (find1[i] && judge)
				a[(i - 1) / 8] += map[1][i];
			if (!judge || find1[i] == 0)
				judge = 0;
		}
		cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3];
		cout << endl;
		//子网掩码
		judge = 1;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= 32; i++)
		{
			a[(i - 1) / 8] *= 2;
			if (find1[i] && judge)
				a[(i - 1) / 8] += 1;
			if (!judge || find1[i] == 0)
				judge = 0;
		}
		cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3];
		cout << endl;
	}
	return 0;
}
