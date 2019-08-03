#include<stdio.h>

int main()
{
	int a = 1;
	for(;a>0;)
	{
		a+= 10000;
	}
	a-=10000;
	for(;a>0;)
	{
		a +=1;
	}
	printf("%d\n",a-1);
	printf("%d\n",a);
	return 0;
}

//2147483647
//-2147483648
