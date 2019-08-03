#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iomanip>
#define maxn 20
using namespace std;

int turn; //0表示白棋走，1表示黑棋走 
char map[maxn][maxn];
int pos[8][2] = { {1,1},{-1,-1},{1,-1},{-1,1},{0,1},{0,-1},{1,0},{-1,0} };
//分别代表 右下 左上 左下 右上 正右 正左 正下 正上 

void O();
void P();
int L(bool);
void M(int, int);


//L 操作 顺便判断一下是否可以操作，不能操作换人
int L(bool is_print)
{
	vector<pair<int, int>> vec;
	char ch1 = turn == 0 ? 'B' : 'W';
	char ch2 = turn == 0 ? 'W' : 'B';
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{

			for (int k = 0; k < 8; k++)
			{
				if (map[i][j] != '-')
					break;
				int x = i;
				int y = j;
				int judge = 1;
				int distance = 0;
				while (1)
				{
					if(x + pos[k][0] < 1 ||
					x + pos[k][0] > 8 ||
					y + pos[k][1] < 1 ||
					y + pos[k][1] > 8)
					break;
					x += pos[k][0];
					y += pos[k][1];
					if (map[x][y] != ch1)
						break;
					distance++;
				}
				if (distance)
				{
					if (map[x][y] == ch2)
					{
						vec.push_back(make_pair(i, j));
						break;
					}
				}
			}
		}
	}
	int size = vec.size();
	if (!is_print)
		return size;
	int first = 1;
	if (size)
		for (int i = 0; i < size; i++)
		{
			if (!first)
				cout << " ";
			cout << "(" << vec[i].first << "," << vec[i].second << ")";
			first = 0;
		}
	else
		cout << "No legal move." ;
	cout << endl;
	return 0; 
}

//M 操作 用L判断是否可以操作 可以的话，八个方向看看
void M(int x,int y)
{
	if (L(false) == 0)
		turn = turn == 0 ? 1 : 0;

	char ch1 = turn == 0 ? 'B' : 'W';
	char ch2 = turn == 0 ? 'W' : 'B';
	map[x][y] = ch2;

	for (int i = 0; i < 8; i++)
	{
		int hx = x;
		int hy = y;
		int judge = 1;
		int distance = 0;
		while (1)
		{
			if(hx + pos[i][0] < 1 ||
			hx + pos[i][0] > 8 ||
			hy + pos[i][1] < 1 ||
			hy + pos[i][1] > 8)
			break;
			hx += pos[i][0];
			hy += pos[i][1];
			if (map[hx][hy]!=ch1)
				break;
			distance++;
		}
		if (distance)
		{
			if (map[hx][hy] == ch2)
			{
				int px = x;
				int py = y;
				for (int j = 1; j <= distance; j++)
				{
					px += pos[i][0];
					py += pos[i][1];
					map[px][py] = ch2;
				}
			}
		}
	}
	P();
	turn = !turn;
}

//O 操作 打印棋盘
void O()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void P()
{
	int Bcnt = 0, Wcnt = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (map[i][j] == 'B')
				Bcnt++;
			if (map[i][j] == 'W')
				Wcnt++;
		}
	}
	cout << "Black -" << setw(3) << Bcnt << " White -"  << setw(3) << Wcnt << endl;
}

int main()
{
	freopen("4-3.in","r",stdin);
	freopen("4-3.out","w",stdout);
	try{
	
	int T;
	cin >> T;
	memset(map, '-', sizeof(map));	
	while (T--)
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				cin >> map[i][j];
		char ch;
		cin >> ch;
		turn = ch == 'W' ? 0 : 1;
		while (cin >> ch)
		{
			if (ch == 'Q')
			{
				O();
				break;
			}
			else if (ch == 'L')
			{
				L(true);
			}
			else if (ch == 'M')
			{
				cin >> ch;
				int x = ch - '0';
				cin >> ch;
				int y = ch - '0';
				M(x, y);
			}
		}
		if(T)
		cout<<endl;
		}
	}
	catch(...)
	{
		
	}
	return 0;
}
