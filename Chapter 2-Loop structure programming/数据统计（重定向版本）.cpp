#define LOCAL
#include<stdio.h>
#define INF 1e10
int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int x,n=0,min=INF,max=-INF,s=0;
	while(scanf("%d",&x)==1)
	{
		s+=x;
		if(x<min)min=x;
		if(x>max)max=x;
		/*
		printf("x=%d,min=%d,max=%d\n",x,min,max);
		*/
		n++;
	}
	printf("%d %d %.3f\n",min,max,(double)s/n);
	return 0;
}
