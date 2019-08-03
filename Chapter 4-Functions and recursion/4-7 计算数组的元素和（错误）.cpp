#include<stdio.h>

//测试中我们发现似乎是可以的
//经过N多测试 发现输出的结果是10
//然而只传了数组指针，可能不保险的缘故，不让用？
//明明只知道首地址啊。可是sizeof还可以用 

int sum(int* a)
{
	int ans=0;
	for(int i=0;i<sizeof(a);i++)
	{
		ans+=a[i];
	}
	return ans;
} 

int main()
{
	int a[]={1,2,3,4};
	printf("%d",sum(a));
	return 0;
}
