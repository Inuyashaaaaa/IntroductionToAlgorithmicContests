#include<stdio.h>
#include<string.h>
#define maxn 100010
int main()
{
	char s[maxn];
	scanf("%s",s);
	int tot=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1')
		tot++;
	}
	printf("%d\n",tot);
	return 0;
} 

/*
1.未包含头文件
2.数组无法开那么大
3.每次都要计算strlen（s）
4.不是等于数字1是字符1 
*/ 
