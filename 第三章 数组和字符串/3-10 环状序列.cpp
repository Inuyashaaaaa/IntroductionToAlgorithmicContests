#include<stdio.h>
#include<string.h>
#define maxn 105

char s[maxn];
int less(int p,int q)
{
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[(i+p)%len] != s[(i+q)%len])
		return  s[(i+p)%len] < s[(i+q)%len];
	} 
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int ans=0;
		int len=strlen(s);
		for(int i= 0;i<len ;i++)
			if(less(i,ans))ans=i;
		for(int i=0;i<len;i++)
			putchar(s[(i+ans)%len]);
		putchar('\n');
	}
	return 0;
}
