#include<stdio.h>
int main()
{
	int a,b,c;
	int kase=0;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		kase++;
		int i;
		for(i=10;i<100;i++)
		{
			if(i%3==a&&i%5==b&&i%7==c)
				break;
		}	
		if(i!=100)
		printf("Case %d: %d\n",kase,i);
		else
		printf("Case %d: No answer\n",kase);
	}
	return 0;
}
