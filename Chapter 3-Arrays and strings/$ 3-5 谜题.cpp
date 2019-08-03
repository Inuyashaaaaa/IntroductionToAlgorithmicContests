#define maxn 5
#include<stdio.h>
char a[maxn][maxn];

void output()
{
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			putchar(a[i][j]);
			if (j != 4)
				putchar(' ');
		}
		putchar('\n');
	}
}

int move(char ch,int& x,int& y)
{
	if (ch == 'A')
	{
		if (x == 0)
			return 0;
		a[x][y] = a[x - 1][y];
		a[--x][y] = ' ';
	}
	else if (ch == 'B')
	{
		if (x == 4)
			return 0;
		a[x][y] = a[x + 1][y];
		a[++x][y] = ' ';
	}
	else if(ch=='L')
	{
		if (y == 0)
			return 0;
		a[x][y] = a[x][y - 1];
		a[x][--y] = ' ';
	}
	else if (ch == 'R')
	{
		if (y == 4)
			return 0;
		a[x][y] = a[x][y + 1];
		a[x][++y] = ' ';
	}
	return 1;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cnt = 0;
	while ((a[0][0] = getchar())!=EOF)
	{
		
		//ZÍË³ö
		if (a[0][0] == 'Z')
			break;
			
		if (cnt++)
			putchar('\n');
		for (int i = 1; i < maxn; i++)
			a[0][i] = getchar();
		getchar();
		for (int i = 1; i < maxn; i++)
		{
			for (int j = 0; j < maxn; j++)
				a[i][j] = getchar();
			getchar();
		}
		
		int x, y;
		x = y = 0;
		int ok = 0;
		for (int i = 0; i < maxn; i++)
		{
			for(int j=0;j<maxn;j++)
				if (a[i][j] == ' ')
				{
					x = i;
					y = j;
					ok = 1;
					break;
				}
			if (ok)
				break;
		}

		//output();
		//printf("%d %d", x, y);
		char ch;
		int judge = 0;
		while (scanf("%c", &ch) == 1)
		{
			if (ch == '0')
				break;
			if (!move(ch, x, y))
			{
				judge = 1;
			}
		}
		printf("Puzzle #%d:\n", cnt);
		if (judge)
			printf("This puzzle has no final configuration.\n");
		else
		{
			output();
		}
		getchar();
	}
}

