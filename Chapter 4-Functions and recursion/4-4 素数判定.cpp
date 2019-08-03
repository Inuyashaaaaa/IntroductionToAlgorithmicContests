#include<stdio.h>
#include<math.h>

//为什么参数类型是int不是long long呢
//因为n很大并不能很快计算出结果
//将在后续继续讨论 

int is_prime(int n)
{
	if(n<=1)
	return 0;
	int m = floor(sqrt(n)+0.5);
	for(int i=2;i<=m;i++)
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
