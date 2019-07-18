#include<stdio.h>
#include<string.h>
#define maxn 55
#define maxm 1005
#define type 4
using namespace std;

char arr[maxn][maxm];
int num[maxm][type];

int retType(char ch)
{
	if(ch=='A')
	return 0;
	if(ch=='C')
	return 1;
	if(ch=='G')
	return 2;
	if(ch=='T')
	return 3;
}

char retAlpha(int index)
{
	if(index==0)
	return 'A';
	if(index==1)
	return 'C';
	if(index==2)
	return 'G';
	if(index==3)
	return 'T';
}

//void output(int m)
//{
//	for(int i=0;i<m;i++)
//	{
//		printf("%s\n",arr[i]);
//	}
//}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			scanf("%s",arr[i]);
		}
		memset(num,0,sizeof(num));
		//注意字典序最小，保持A情况
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				num[j][retType(arr[i][j])]++;
			}
		} 
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int max = num[i][0];
			char maxAlpha = 'A';
			for(int j=1;j<4;j++)
			{
				if(num[i][j]>max)
				{
					max=num[i][j];
					maxAlpha = retAlpha(j);
				}
			}
			for(int j=0;j<4;j++)
			{
				if(maxAlpha!=retAlpha(j))
				sum+=num[i][j];
			}
			printf("%c",maxAlpha);
		}
		printf("\n");
		printf("%d\n",sum);
		
//		output(m);
	}
	return 0;
}
