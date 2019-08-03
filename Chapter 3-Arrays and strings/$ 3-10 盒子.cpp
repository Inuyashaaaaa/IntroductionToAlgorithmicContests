#include<stdio.h>
#include<string.h>
struct Box {
	int h;
	int w;
	Box()
	{

	}
	Box(int c, int b)
	{
		if (c > b)
		{
			h = c;
			w = b;
		}
		else
		{
			h = b;
			w = c;
		}
	}
	friend bool operator == (Box b1, Box b2)
	{
		return b1.h == b2.h && b1.w == b2.w;
	}
};

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		Box box[6];
		int mark[6];
		memset(mark, 1, sizeof(mark));
		box[0] = Box(a, b);
		int size = 1;
		for (int i = 1; i < 6; i++)
		{
			int judge = 1;
			scanf("%d%d", &a, &b);
			for (int j = 0; j < size; j++)
			{
				Box t = Box(a, b);
				if (t == box[j])
				{
					mark[j]++;
					judge = 0;
					break;
				}
			}
			if (judge)
			{
				box[size] = Box(a, b);
				size++;
			}
		}
		if (size > 3)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		int judge3 = 1;
		for (int i = 0; i < size; i++)
		{
			if (mark[i] % 2 == 1)
			{
				printf("IMPOSSIBLE\n");
				judge3 = 0;
				break;
			}
		}
		if (!judge3)
			continue;


		int s = 0;
		for (int i = 0; i < size; i++)
		{
			s ^= box[i].w;
			s ^= box[i].h;
		}
		if (s == 0 || (size==2 && ((box[0].w^box[0].h)==s || (box[1].w^box[1].h) == s)))
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
}
