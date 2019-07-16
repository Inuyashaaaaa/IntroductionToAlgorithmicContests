//#include<stdio.h>
//int main()
//{
//	int n,S = 0;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//	{
//		int factorial = 1;
//		for(int j=1;j<=i;j++)
//			factorial *= j;
//		S+=factorial;
//	}
//	printf("%d",S%1000000);
//	return 0;
//}

//以上的算法会造成乘法溢出，不合适

#include<stdio.h>
#include<time.h>
int main()
{
	const int MOD = 1e6;
	int n,S = 0;
	scanf("%d",&n);
	if(n>25) n=25;
	for(int i=1;i<=n;i++)
	{
		break;
		int factorial = 1;
		for(int j=1;j<=i;j++)
		{
			factorial = (factorial * j % MOD);
		}
		S = (S+factorial) % MOD;
	}
	printf("%d\n",S);
	printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
} 
