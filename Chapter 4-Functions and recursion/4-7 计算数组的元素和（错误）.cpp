#include<stdio.h>

//���������Ƿ����ƺ��ǿ��Ե�
//����N����� ��������Ľ����10
//Ȼ��ֻ��������ָ�룬���ܲ����յ�Ե�ʣ������ã�
//����ֻ֪���׵�ַ��������sizeof�������� 

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
