#include<stdio.h>
#include<string.h>
#define maxn 100
int left,chance; 		//left代表还有多少个没有猜中 chance代表机会还剩几次
int win,lose;			//win,lose为1代表状态成立
char s[maxn],s2[maxn];	//s代表正确的字符串，s2代表猜测的字符串

void guess(char ch)
{
	int bad = 1;
	int len = strlen(s); 
	for(int i=0;i<len;i++)
		if(s[i]==ch)
		{
			bad = 0;
			s[i]=' ';
			left--;
		}
	if(bad) 
		chance--;
	if(!left)
		win=1;
	if(!chance)
		lose=1;
} 

int main()
{
	int rnd;
	while(scanf("%d%s%s",&rnd,s,s2)==3 && rnd!=-1)
	{
		printf("Round %d\n",rnd);
		left = strlen(s);
		chance=7;
		win = lose = 0;
		int len = strlen(s2);
		for(int i=0;i<len;i++)
		{
			guess(s2[i]);
//			printf("%c\n",s2[i]);
//			printf("%d %d\n",left,chance);
			if(win || lose)
			break;
		}
		if(win)
		printf("You win.");
		else if(lose)
		printf("You lose.");
		else
		printf("You chickened out.");
		printf("\n");
	}
	return 0;
}
