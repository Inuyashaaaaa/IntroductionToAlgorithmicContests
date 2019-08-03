#include<stdio.h>
#include<string.h>
#define maxn 10000

struct command{
	char c[5];
	int r1,c1,r2,c2;
	int a,x[20];
}cmd[maxn];

int r,c,n;

int simulate(int& r0,int& c0)
{
	for(int i=0;i<n;i++)
	{
		if(cmd[i].c[0] == 'E'){
			if(r0 == cmd[i].r1 && c0 == cmd[i].c1)
			{
				r0 = cmd[i].r2;
				c0 = cmd[i].c2; 
			}
			else if(r0 == cmd[i].r2 && c0 == cmd[i].c2)
			{
				r0 = cmd[i].r1;
				c0 = cmd[i].c1;
			}
		}
		else
		{
			int dr = 0;
			int dc = 0;
			for(int j=0;j<cmd[i].a;j++)
			{
				int x = cmd[i].x[j];
				if(cmd[i].c[0]=='D')
				{
					if(cmd[i].c[1]=='R' && r0 == x) return 0;
					if(cmd[i].c[1]=='R' && r0 > x) dr--;
					if(cmd[i].c[1]=='C' && c0 == x) return 0;
					if(cmd[i].c[1]=='C' && c0 > x) dc--;
 				}
 				else
 				{
 					if(cmd[i].c[1]=='R' && r0 >= x) dr++;
 					if(cmd[i].c[1]=='C' && c0 >= x) dc++;
 				}
			}
			r0 += dr;
			c0 += dc;
		}
	} 
	return 1;
}

int main()
{
	int r0,c0,q,kase=0;
	while(scanf("%d%d%d",&r,&c,&n)==3 && r)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd[i].c);
			if(cmd[i].c[0] == 'E')
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else
			{
				scanf("%d",&cmd[i].a);
				for(int j=0;j<cmd[i].a;j++)
					scanf("%d",&cmd[i].x[j]);
			}
		}
		
		if(kase++>0)
		printf("\n");
		printf("Spreadsheet #%d\n",kase);
		
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&r0,&c0);
			printf("Cell data in (%d,%d) ",r0,c0);
			if(simulate(r0,c0)) 
			printf("moved to (%d,%d)\n",r0,c0);
			else
			printf("GONE\n");
		}
	}
}
