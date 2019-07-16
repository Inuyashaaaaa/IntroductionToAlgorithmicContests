#include<stdio.h>
int main()
{
	int a,b,c;
	int kase=0;
	while(scanf("%d%d%d",&a,&b,&c)==3&&a+b+c!=0)
	{
		printf("Case %d: %.*f\n",++kase,c,a*1.0/b);
	}
	return 0;
} 
