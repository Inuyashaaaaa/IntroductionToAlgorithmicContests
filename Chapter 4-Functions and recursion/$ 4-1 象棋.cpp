#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#define row 15
#define col 15

using namespace std;
char map[row][col];
int redGx;
int redGy;
//以棋盘左上角为（1，1）

vector<pair<int, int>> vec;//第0个是黑将的初始位置 后面是各个红棋子的位置
int Gpos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //代表将可以走的4个位置（右，左，下，上）
int Hpos[8][2] = { {1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };//代表马可以走的八个位置（右偏下，右偏上，左偏下，左偏上，下偏右，下偏左，上偏右，上偏左）
int n;//多少枚棋子

bool testPos(const int&, const int&);
bool store();
bool moveBlackG();
int numOfPiece(char type, int x1, int y1, int x2, int y2);

//判断移动后的黑将是否被杀
bool moveBlackG()
{
	//初始位置
	int x = vec[0].first;
	int y = vec[0].second;
	if (y == redGy)
	{
		if (numOfPiece('R', x, y, redGx, redGy) == 0)
			return true;
	}
	int x1;
	int y1;
	int judge = 0;
	for (int i = 0; i < 4; i++)
	{
		x1 = x;
		y1 = y;
		if (x + Gpos[i][0] < 1 || x + Gpos[i][0]>3 ||
			y + Gpos[i][1] < 4 || y + Gpos[i][1]>6)
			continue;
		x1 += Gpos[i][0];
		y1 += Gpos[i][1];
		if (testPos(x1, y1))
		{
			judge = 1;
			break;
		}
	}
	return judge;
}

//测试新位置是否健康
bool testPos(const int& x, const int& y)
{
	for (int i = 1; i <= n; i++)
	{
		int x1 = vec[i].first;
		int y1 = vec[i].second;
		if (map[x1][y1] == 'R')
		{
			if (x1 == x && y1 == y)
				continue;
			if (x1 == x)
				if (numOfPiece('C', x1, y1, x, y) == 0)
					return false;
			if (y1 == y)
				if (numOfPiece('R', x1, y1, x, y) == 0)
					return false;
		}
		else if (map[x1][y1] == 'C')
		{
			if (x1 == x)
				if (numOfPiece('C', x1, y1, x, y) == 1)
					return false;
			if (y1 == y)
				if (numOfPiece('R', x1, y1, x, y) == 1)
					return false;
		}
		else if (map[x1][y1] == 'H')
		{
			for (int i = 0; i < 4; i++)
			{
				int hx = x1 + Gpos[i][0];
				int hy = y1 + Gpos[i][1];
				if (hx < 1 || hx>10 || hy < 1 || hy>9)
					continue;
				if (map[hx][hy] != '0')
					continue;
				for (int j = i * 2; j < (i + 1) * 2; j++)
				{
					int xh = x1 + Hpos[j][0];
					int yh = y1 + Hpos[j][1];
					if (xh == x && yh == y)
						return false;
				}
			}
		}
		else if (map[x1][y1] == 'G')
		{
			if (numOfPiece('R', x, y, x1, y1) == 0)
				return false;
		}
	}
	return true;

}


//判断两个棋子的行/列中间有几个棋子
int numOfPiece(char type, int x1, int y1, int x2, int y2)
{
	int cnt = 0;
	if (type == 'R')
	{
		if (y1 != y2)
			return -1;
		if (x1 > x2)
			swap(x1, x2);

		for (int i = x1 + 1; i < x2; i++)
		{
			if (map[i][y1] != '0')
				cnt++;
		}
	}
	else
	{
		if (x1 != x2)
			return -1;
		if (y1 > y2)
			swap(y1, y2);
		for (int i = y1 + 1; i < y2; i++)
		{
			if (map[x1][i] != '0')
				cnt++;
		}
	}
	return cnt;
}
int main()
{

	int a, b;
	while (cin >> n >> a >> b && a && n && b)
	{
		vec.clear();
		memset(map, '0', sizeof(map));
		vec.push_back(make_pair(a, b));
		for (int i = 1; i <= n; i++)
		{
			char ch;
			int x, y;
			cin >> ch >> x >> y;
			map[x][y] = ch;
			vec.push_back(make_pair(x, y));
			if (ch == 'G')
			{
				redGx = x;
				redGy = y;
			}
		}
		if (moveBlackG())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}


