#include<stdio.h>
int main()
{
	int count=0;
	printf("%d %d %d\n",count++,count++,count++);//�������� 
	count = count++; //count++�󴢴�ֵԭ�� count+1 Ȼ���ٸ�ֵ count��Ϊ����ֵ��û�б任�� 
	printf("%d",count);
	return 0;
}
