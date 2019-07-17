#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 100

double getMolarMass(char ch)
{
	if(ch=='C')
	return 12.01;
	if(ch=='H')
	return 1.008;
	if(ch=='O')
	return 16.00;
	if(ch=='N')
	return 14.01;
}

int main()
{
	int T;
	scanf("%d",&T);
	char s[maxn];
	while(T--)
	{
		memset(s,'p',sizeof(s));	
		scanf("%s",s);
		int len = strlen(s);
		double sum = 0;
		for(int i=0;i<len;i++)
		{
			if(isalpha(s[i]))
			{
				if(isdigit(s[i+1])&&isdigit(s[i+2]))
				{
					sum+=getMolarMass(s[i])*((s[i+1]-'0')*10+s[i+2]-'0');
					i+=2;
					continue; 
				}
				else if(isdigit(s[i+1]))
				{
					sum+=getMolarMass(s[i])*(s[i+1]-'0');
					i+=1;
					continue;
				}
				else
				{
					sum+=getMolarMass(s[i]);
				}
			}
		}
		printf("%.3f\n",sum);
	}
	return 0;
}
