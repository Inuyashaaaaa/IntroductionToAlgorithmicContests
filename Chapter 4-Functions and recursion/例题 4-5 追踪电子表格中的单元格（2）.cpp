#include<stdio.h>
#include<string.h>
#define maxn 100
int r,c,n,d[maxn][maxn],d2[maxn][maxn],ans[maxn][maxn],cols[maxn];

void copy(char type,int p,int q)
{
	if(type=='R')
		for(int i=1;i<=c;i++)
			d[p][i]=d2[q][i];
	else
		for(int i=1;i<=r;i++)
			d[i][p]=d2[i][q];
}

void del(char type)
{
	memcpy(d2,d,sizeof(d));
	int cnt = type =='R' ? r:c;
	int cnt2=0;
	for(int i=1;i<=cnt;i++)
		if(!cols[i])copy(type,++cnt2,i);
	if(type=='R')
	r = cnt2;
	else
	c = cnt2;
}

void ins(char type)
{
	memcpy(d2,d,sizeof(d));
	int cnt = type == 'R' ? r:c;
	int cnt2=0;
	for(int i=1;i<=cnt;i++)
	{
		if(cols[i]) copy(type,++cnt2,0);
		copy(type,++cnt2,i);
	}
	if(type=='R')
	r=cnt2;
	else
	c=cnt2;
}

int main()
{
	int r1,c1,r2,c2,q,kase=0;
	char cmd[10];
	memset(d,0,sizeof(d));
	while(scanf("%d%d%d",&r,&c,&n)==3 && r)
	{
		int r0 = r;
		int c0 = c;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				d[i][j] = i*maxn + j;
		while(n--)
		{
			scanf("%s",cmd);
			if(cmd[0]=='E')
			{
				scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
				int t = d[r1][c1];
				d[r1][c1] = d[r2][c2];
				d[r2][c2] = t;
			}
			else
			{
				int a,x;
				scanf("%d",&a);
				memset(cols,0,sizeof(cols));
				for(int i=1;i<=a;i++)
				{
					scanf("%d",&x);
					cols[x] = 1;
				}
				if(cmd[0] == 'D') del(cmd[1]);
				else ins(cmd[1]); 
			}
		}
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				ans[d[i][j]/maxn][d[i][j]%maxn] = i*maxn+j;
		if(kase>0)
		printf("\n");
		printf("Spreadsheet #%d\n",++kase);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&r1,&c1);
			printf("Cell data in (%d,%d) ",r1,c1);
			if(ans[r1][c1]==0)printf("GONE\n");
			else printf("moved to (%d,%d)\n",ans[r1][c1]/maxn,ans[r1][c1]%maxn);
		} 
	}
	return 0;
}
