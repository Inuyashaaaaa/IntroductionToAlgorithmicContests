#include<stdio.h>
#define maxn 25
int n,k,m,a[maxn];
//n代表多少人 
//k代表第一个逆时针走的官员 一次走多少步
//m代表第二个顺时针走的官员 一次走多少步 

int go(int p,int d,int t)
{
	while(t--)
	{
		p = (p+d+n-1)%n+1;
		if(a[p]==0)
		t++;
	}
	return p;
}

int main()
{
	while(~scanf("%d%d%d",&n,&k,&m) && n)
	{
		for(int i=1;i<=n;i++) a[i]=i;
		int left = n;
		int p1 = n;
		int p2 = 1;
		while(left)
		{
			p1 = go(p1,1,k);
			p2 = go(p2,-1,m);
			printf("%3d",p1);
			left--;
			if(p1!=p2)
			{
				printf("%3d",p2);
				left--;
			}
			a[p1] = a[p2] = 0;
			if(left)
			printf(",");
		}
		
	}
}
