#include<stdio.h>
#include<string.h>
#define maxn 10000
int a[maxn];
int b[maxn];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		printf("%d/%d = %d.", n, m, n / m);
		int count = 1;
		n = n % m;
		while (!b[n] && n)
		{
			b[n] = count;
			a[count++] = n * 10 / m;
			n = n * 10 % m;
		}
		if (n == 0)
		{
			for (int i = 1; i < count; i++)
				printf("%d", a[i]);
			printf("(0)\n");
		}
		else
		{
			int i;
			for (i = 1; i < b[n]; i++)
				printf("%d", a[i]);
			printf("(");
			for (; i < count&&i <= 50; i++)
				printf("%d", a[i]);
			if (count > 50)
				printf("...");
			printf(")\n");
		}
		printf("   %d", !n ? 1 : count - b[n]);
		printf(" = number of digits in repeating cycle\n\n");
	}
	return 0;
}
