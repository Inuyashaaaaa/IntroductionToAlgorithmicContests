#include<stdio.h>
#include<string.h>
#define maxn 100

int main()
{
	int T;
	scanf("%d",&T);
	char s[maxn];
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		int sum=0;
		int cnt=0;
		for(int i=0;i<len;i++)
			if(s[i]=='X')
			cnt=0;
			else
			sum+=++cnt; 
		printf("%d\n",sum);
	}
	return 0;
} 
