#include<stdio.h>
#include<string.h>
#define maxn 100005
int ans[maxn];

int getValue(int a)
{
	int e=0;
	while(a)
	{
		e+=a%10;
		a/=10;
	}
	return e;
}

int main()
{
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=maxn;i++)
	{
		int y=i;
		y+=getValue(i);
		if(ans[y]==0)
		ans[y]=i;
	}
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}
