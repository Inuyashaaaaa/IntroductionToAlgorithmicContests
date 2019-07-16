#include<stdio.h>
int main()
{
	int A,B,C;
	for(int i=100;i<1000;i++)
	{
		A=i%10;
		B=i/10%10;
		C=i/100;
		if(A*A*A+B*B*B+C*C*C==i)
		printf("%d\n",i);
	}
	return 0;
}
