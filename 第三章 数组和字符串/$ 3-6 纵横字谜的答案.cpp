#include<stdio.h>
#include<string.h>
#define maxn 12

char a[maxn][maxn];
int b[maxn][maxn];

void mark(int r,int c)
{
	int cnt=1;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if((a[i-1][j]=='*' || a[i][j-1] == '*') && a[i][j]!='*')
			b[i][j]=cnt++;
		}
	}
}

void out(int r,int c)
{
	printf("Across\n");
	int flag = 0;
	for(int i=1;i<=r;i++)
	{
		if(flag)
		printf("\n");
		flag=0;
		for(int j=1;j<=c;j++)
		{
			if(!flag && b[i][j])
			{
				printf("%3d.%c",b[i][j],a[i][j]);
				flag=1;
			}
			else if(flag && a[i][j]!='*')
				printf("%c",a[i][j]);
			else if(flag && a[i][j]=='*')
			{
				flag=0;
				printf("\n");
			}
			
		}
	}
	if(flag)
	printf("\n");
	printf("Down\n");
	flag = 0;
	int find[maxn][maxn];
	memset(find,0,sizeof(find)); 
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(!find[i][j] && a[i][j]!='*')
			{
				find[i][j]==1;
				printf("%3d.%c",b[i][j],a[i][j]);
				int m=i;
				while(a[++m][j]!='*')
				{
					find[m][j]=1;
					printf("%c",a[m][j]);
				}
				printf("\n");
			}
		}
	}
}

//void output(int r,int c)
//{
//	for(int i=1;i<=r;i++)
//	{
//		for(int j=1;j<=c;j++)
//		printf("%c",a[i][j]);
//		putchar('\n');
//	}
//	
//	for(int i=1;i<=r;i++)
//	{
//		for(int j=1;j<=c;j++)
//		printf("%d",b[i][j]);
//		putchar('\n');
//	}
//}

int main()
{
	int r,c;
	int cnt=0;
	while(scanf("%d",&r)==1)
	{
		if(r==0)
		break;
		if(cnt++)
		putchar('\n');
		scanf("%d",&c);
		memset(a,'*',sizeof(a));
		memset(b,0,sizeof(b));
		getchar();
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			scanf("%c",&a[i][j]);
			getchar();
		}	
		printf("puzzle #%d:\n",cnt);
		mark(r,c);
		out(r,c);	 
	}
	return 0;
}
