#include<stdio.h>

//n=1 或者 n太大的时候不要用 
//这里的i*i可能导致溢出 

int is_prime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
} 

int main()
{
	printf("%d",is_prime(2));
	return 0;
}
