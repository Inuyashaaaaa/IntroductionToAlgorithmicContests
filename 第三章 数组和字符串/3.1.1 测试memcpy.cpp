#include<stdio.h>
#include<string.h>
double a[100];
double b[100];

int main()
{
	for(int i=0;i<100;i++)
	{
		a[i] = i +1;
	}
	memcpy(b,a,sizeof(a));
	for(int i=0;i<100;i++)
	{
		printf("%f ",b[i]);
	}
	return 0;
} 
