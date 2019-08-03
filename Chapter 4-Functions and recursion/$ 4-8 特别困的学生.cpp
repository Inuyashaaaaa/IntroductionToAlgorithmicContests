#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio> 
using namespace std;

char map[20][10010];

//传入数组和个数，返回最小公倍数
int minCommonMultiple(int* a,int n)
{
	int ret = 10;
	for (int i = 0; i < n; i++)
	{
		if (ret%a[i] != 0)
			ret *= a[i];
	}
	return ret;
}

struct Info {
	int a;
	int b;
	int c;//first
};

int main()
{
	freopen("4-8.in","r",stdin);
	freopen("4-8.out","w",stdout);
	int T;
	int cnt = 0;
	int a[10];
	Info info[10];
	for (int i = 0; i < 20; i++)
	{
		map[i][0] = '#'; //第0分钟默认全睡觉了
	}
	while (cin >> T && T)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < T; i++)
		{
			cin >> info[i].a >> info[i].b >> info[i].c;
			a[i] = info[i].a + info[i].b;
		}
		int ret = minCommonMultiple(a, T);
		int index = -1;
		for (int i = 1; i <= ret; i++)
		{
			int cntt = 0;
			for (int j = 0; j < T; j++)
			{
				if (info[j].c <= info[j].a)
					map[j][i] = '*'; //表示没睡觉
				if (info[j].c == info[j].a + 1)
				{
					int cnt1 = 0;
					int cnt2 = 0;
					for (int j = 0; j < T; j++)
					{
						if (map[j][i - 1] == '*')
							cnt1++;
						if (map[j][i - 1] == '#')
							cnt2++;
					}
					if (cnt2 > cnt1)
						map[j][i] = '#';
					else
					{
						info[j].c -= info[j].a;
						map[j][i] = '*';
					}
				}
				if (info[j].c > info[j].a + 1 && info[j].c <= info[j].a + info[j].b)
					map[j][i] = '#';
				if (info[j].c == info[j].a + info[j].b)
					info[j].c = 0;
				info[j].c++;
				if (map[j][i] == '*')
					cntt++;
			}
			if (cntt == T)
			{
				index = i;
				break;
			}
		}

		cout << "Case " << ++cnt << ": " << index << endl;

	}

	return 0;
}
