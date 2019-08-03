#include<stdio.h>
#include<string.h> 

int cnt[10]; 
void getValue(int a)
{
	while(a)
	{
		cnt[a%10]++;
		a/=10;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			getValue(i);
		for(int i=0;i<9;i++)
			printf("%d ",cnt[i]);
		printf("%d\n",cnt[9]);
	}
	return 0;
}
