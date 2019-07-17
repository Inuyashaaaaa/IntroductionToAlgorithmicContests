#include<stdio.h>
int main()
{
	int count=0;
	printf("%d %d %d\n",count++,count++,count++);//从右往左 
	count = count++; //count++后储存值原本 count+1 然后再赋值 count变为储存值（没有变换） 
	printf("%d",count);
	return 0;
}
