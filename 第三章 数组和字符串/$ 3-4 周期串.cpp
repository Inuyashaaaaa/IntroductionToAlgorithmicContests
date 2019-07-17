#include<stdio.h>
#include<string.h>
#define maxn 100

int main()
{

	int T;
	int cnt=0;
	scanf("%d",&T);
	while(T--)
	{
		if(cnt++)
		printf("\n");
		int ans=1;
		char s[100];
		scanf("%s",s);
		int len=strlen(s);
		
		for(;ans<len;ans++)
		{
			if(len%ans!=0)
			continue;
			int judge=0;
			for(int i=0;i<ans;i++)
			{		
				for(int j=i+ans;j<len;j+=ans)
				{
					if(s[i]!=s[j])
					{
						judge=1;
						break;
					}
				}
				if(judge)
				break; 
			} 
			if(!judge)
			break;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
