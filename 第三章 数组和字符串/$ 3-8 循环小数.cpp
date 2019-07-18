#include<stdio.h>
#define maxn 3030
int num[3030];//保存输出数字 
int ans[3030];//保存可被除数字 

int main()
{
	freopen("data.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	int n, m;
	int first = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (first++)
			printf("\n");
		printf("%d/%d = ", n, m);
		if (n > m)
		{
			printf("%d.", n / m);
			n -= (n / m * m);
		}
		else
			printf("0.");
		int size1 = 0; //输出 
		int size2 = 0; //可被除 
		int index = -1;
		while (1)
		{	
			n *= 10;
			int judge = 0;
			while (n < m)
			{
				num[size1] = 0;
				size1++;
				n *= 10;
			}
			for (int i = 0; i < size2; i++)
			{
				if (n == ans[i])
				{
					index = i;
					judge = 1;
				}
			}
			if (judge)
				break;
			ans[size2] = n;
			size2++;
			num[size1] = n / m;
			size1++;
			n -= (n / m * m);
			if (n == 0)
				break;
		}
		int cnt = 0;
		int cnt2 = 0;
		int judge3 = 1;
		int judge2 = 0;
		if (index == -1)
		{
			for (int i = 0; i < size1; i++)
			{
				printf("%d", num[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n");
		}
		else
		{
			for (int i = 0; i < size1; i++)
			{
				if(i==50)
				{
					printf("...");
					break;
				}
				if (index == i)
				{
					printf("(");
					judge2 = 1;
				}
				printf("%d", num[i]);
				if (judge2)
				{
					if (judge3)
					{
						if (num[i] == 0)
							size1--;
						else
							judge3 = 0;
					}
				}
			}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n", size1 - index);
		}

	}
	return 0;
}
