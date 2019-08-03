#include<stdio.h>

//int sum(int* begin,int* end)
//{
//	int ans=0;
//	int n = end-begin;
//	for(int i=0;i<n;i++)
//		ans+=begin[i];
//	return ans;
//} 

int sum(int* begin,int* end)
{
	int ans=0;
	for(int* p=begin;p!=end;p++)
		ans+=*p;
	return ans;
}

int main()
{
	int a[]={1,2,3,4};
	printf("%d",sum(a,a+4));
	return 0;
}
