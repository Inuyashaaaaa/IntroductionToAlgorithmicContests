#include<stdio.h>

//C n m
//��Ȼ����n��m�ܴ��ʱ�����
//���Ƚ�����һ������������ 
long long C(int n,int m)
{
	if(m<n-m) m=n-m;
	long long ans = 1;
	for(int i=m+1;i<=n;i++) ans*=i;
	for(int i=1;i<=n-m;i++) ans/=i;
	return ans;
} 

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		printf("%lld",C(n,m));
	}
	return 0;
}
