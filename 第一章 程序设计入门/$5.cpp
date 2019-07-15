#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n<4)
		printf("%d",n*95);
	else
		printf("%d",n*95*17/20);
		
	return 0;
}
