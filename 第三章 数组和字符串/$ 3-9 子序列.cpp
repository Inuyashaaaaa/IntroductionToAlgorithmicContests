#include<stdio.h>
#include<string.h> 
#define maxn 1001000 

int main()
{
	char s[maxn];
	char t[maxn];
	while(~scanf("%s%s",s,t))
	{
		int judge=0;
		int cnt = 0;
		int len = strlen(t);
		for(int i=0;i<len;i++)
		{
			if(s[cnt]==t[i]) 
			cnt++;
			if(cnt == strlen(s))
			{
				judge=1;
				break;
			}
		}
		if(judge)
			printf("Yes\n");
		else
			printf("No\n");
		 
		 
	} 
} 
