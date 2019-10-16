#include<cstdio>
#include<cstring>
#include<cctype>
#define REP(i, a, b) for(int i = (a); i < (b); i++)   //为了偷懒， 主要是小于b, 不是小于等于 
using namespace std;
 
const char* word = "*+-!";   //这里！表示不加符号， 这个顺序不能错， 是字典序 
char str[20], symbol[20], sign[20];  //symbol是用来存枚举的符号， 而sign是计算表达式用到的存符号栈 
int ok, len, topn, tops, num[20];  //num是计算表达式用到的存数字栈  
 
bool get_string(char (&s)[20])   //这里是引用数组， 类型名 （&变量名）[N]；  
{
	int pos = 0;
	REP(i, 0, len - 1)   //等号忽略， 所以是len - 1 
	{
		s[pos++] = str[i];
		if(symbol[i] != '!') 
			s[pos++] = symbol[i];
	}
	
	if(s[0] == '0' && isdigit(s[1])) return false;    //这下面一段是判断前导0， 第一个字符特判一下 
	REP(i, 1, pos)
		if(!isdigit(s[i-1]) && s[i] == '0' && isdigit(s[i+1]))   //前面是符号，中间是数字， 后面也是数字
			return false;                                        // 这样不会是单个0， 这样就有前导0 
	return true;
}
 
void cal()
{
	char t = sign[tops--];
	if(t == '+') num[--topn] += num[topn+1];
	else if(t == '-') num[--topn] -= num[topn+1];
	else num[--topn] *= num[topn+1];
}
 
int f(char x) { return x == '!' ? 0 : x == '*' ? 2 : 1; } 
														
int get_val(char* s)                                       
{                                                          
	int x = 0;
	topn = tops = 0;
		
	REP(i, 0, strlen(s))
	{
		if(isdigit(s[i])) x	= x * 10 + s[i] - '0';
		else
		{
			num[++topn] = x;
			x = 0;
			while(f(s[i]) <= f(sign[tops])) cal();
			sign[++tops] = s[i];
		}
		if(i == strlen(s) - 1) num[++topn] = x;   //最后一个数不要漏 
	}
		
	while(tops) cal();  //计算遗留下来的符号 
	return num[1];
}
 
void check_ans()
{
	char s[20];
	if(!get_string(s)) return;
	if(get_val(s) == 2000)
	{
		printf("  %s=\n", s);
		ok = true;
	}
}
 
void search(int d)
{
	if(d == strlen(str) - 2) { check_ans(); return; } 
	REP(i, 0, 4)
	{
		symbol[d] = word[i];
		search(d + 1);
	}
}
 
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int kase = 0;
	while(scanf("%s", str) && strcmp(str, "="))
	{
		memset(symbol, 0, sizeof(symbol));
		memset(num, 0, sizeof(num));
		memset(sign, 0, sizeof(sign));
		sign[0] = '!';                        //见36行注释 
		
		ok = false;
		len = strlen(str);
		printf("Problem %d\n", ++kase);
		if(!strcmp(str, "2000="))            //这里有个坑， 要特判一下 
		{
			puts("  IMPOSSIBLE");
			continue;
		}
		search(0);	
		if(!ok) puts("  IMPOSSIBLE");
	}
	return 0;	
} 