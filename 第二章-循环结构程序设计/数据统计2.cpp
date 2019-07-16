#include<stdio.h>
#define INF 1e10
int main()
{
	int x,n=0, kase=0;
	while(scanf("%d",&n)==1&&n)
	{
		int s=0;
		int max=-INF,min=INF;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s+=x;
			if(x<min)min=x;
			if(x>max)max=x;
		}
		if(kase) printf("\n");
		printf("Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
	}
	return 0;
}
