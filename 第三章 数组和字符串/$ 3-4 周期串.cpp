#include<stdio.h>
#include<string.h>
#define maxn 100

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s[maxn];
		scanf("%s",s);
		int len=strlen(s);
		int step;
		for(step=1;step<=len/2;step++)
		{
			int judge=1;
			for(int j=0;j<step;j++)
			{
				for(int i=j;i<len-step;i+=step)
				{
					if(s[i]!=s[i+step])
					{
						judge=0;
						break;
					}
				}
				if(!judge)
				break;
			}
			if(judge)
			break;
		}
		if(T)
		printf("%d\n\n",step);
		else
		printf("%d\n",step);
	}
	return 0;
}
