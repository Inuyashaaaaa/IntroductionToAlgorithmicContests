#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 105

int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	char s1[maxn];
	char s2[maxn];
	while(~scanf("%s%s",s1,s2))
	{
		int a1[26];
		int a2[26];
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		int len1=strlen(s1);
		int len2=strlen(s2);
		for(int i=0;i<len1;i++)
			a1[s1[i]-'A']++;
		for(int i=0;i<len2;i++)
			a2[s2[i]-'A']++;
		qsort(a1,26,sizeof(int),cmp);
		qsort(a2,26,sizeof(int),cmp);
		int judge=0;
		for(int i=0;i<26;i++)
			if(a1[i]!=a2[i])
			{
				judge=1;
				break;
			}
		if(judge)
			printf("NO\n");
		else
			printf("YES\n"); 
	}
	return 0;
}


