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
1.δ����ͷ�ļ�
2.�����޷�����ô��
3.ÿ�ζ�Ҫ����strlen��s��
4.���ǵ�������1���ַ�1 
*/ 
