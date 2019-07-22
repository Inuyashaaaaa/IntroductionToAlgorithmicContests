#include<iostream>
#include<string>
#include<iomanip>
#include<cstdio>
#define maxn 10
#define maxc 1000
using namespace std;
string map[maxc][maxc];
int d, s, b;
int type;

void output()
{
	for (int i = 0; i < d; i++)
		cout << setw(9) << "DISK " << i + 1;
	cout << endl;
	for (int i = 0; i < b; i++)
	{	
		for (int j = 0; j < d; j++)
		{
			cout << setw(10) << map[j][i];
		}
		cout << endl;
	}
}

void parse()
{
	int cnt = 0;
	int temp = 0;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < d; j++)
		{		
			for (int k = 0; k < s; k++)
			{
				if (i % d == j)
					continue;
				cnt++;
				temp *= 2;
				temp += map[j][i][k] - '0';
				if (cnt % 4 == 0)
				{
					printf("%X",temp);
					temp = 0;
				}
			}
		}
	}
	if (cnt % 4 != 0)
		printf("%X", (temp << (4 - cnt % 4)));
}

bool process()
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < s; j++)
		{
			int w = 0;
			int cnt = 0;
			int index;
			for (int k = 0; k < d; k++)
			{
				if (map[k][i][j] == 'x')
				{
					index = k;
					cnt++;
					if (cnt == 2)
						return false;
					continue;
				}
				w^=map[k][i][j] - '0';
			}
			if (cnt == 1)
			{
				if (1 ^ w == type)
					map[index][i][j] = 1 + '0';
				else
					map[index][i][j] = 0 + '0';
			}
			if (cnt == 0 && w != type)
				return false;
			
		}
	}
	return true;
}

int main()
{
//	freopen("4-7.in","r",stdin);
//	freopen("4-7.out","w",stdout);
	int cnt = 0;
	while (cin >> d && d)
	{
		cin >> s >> b;
		char ch;
		cin >> ch;
		type = ch == 'E' ? 0 : 1;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < b; j++)
			{
				string s1;
				for (int k = 0; k < s; k++)
				{
					cin >> ch;
					s1 += ch;
				}
				map[i][j] = s1;
			}
		}


		output();
		if (process())
		{
			cout << "Disk set " << ++cnt << " is valid, contents are: ";
			parse();
			cout << endl;
		}
		else
		{
			cout << "Disk set " << ++cnt << " is invalid." << endl;
		}
		output();
	}
	return 0;
}
