#include<stdio.h>
#include<math.h>

//Ϊʲô����������int����long long��
//��Ϊn�ܴ󲢲��ܺܿ��������
//���ں����������� 

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
