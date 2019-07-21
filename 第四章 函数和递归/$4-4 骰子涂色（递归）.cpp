#include<iostream>
#include<cstdio>
using namespace std;
char ans[6];

bool f(int i,char* s)
{
	char temp[6];
	bool isok = true;
	for (int i = 0; i < 6; i++)
	{
		if (ans[i] != s[i])
			isok = false;
	}
	if (isok)
		return true;
	if (i == 0)
		return false;
	for (int i = 0; i < 6; i++)
		temp[i] = s[i];
	char ch = temp[0];
	temp[0] = temp[1];
	temp[1] = temp[5];
	temp[5] = temp[4];
	temp[4] = ch;
	ch = s[3];
	s[3] = s[1];
	s[1] = s[2];
	s[2] = s[4];
	s[4] = ch;
	return f(i - 1, temp)|| f(i - 1, temp);
}

int main()
{
	char s[20];
	freopen("4-4.in","r",stdin);
	freopen("4-4.out","w",stdout);
	while (cin >> s)
	{
		char s1[6];
		for (int i = 0; i < 6; i++)
		{
			s1[i] = s[i];
			ans[i] = s[i + 6];
		}
		cout << ((f(6, s1) == true) ? "TRUE" : "FALSE") << endl;
	}
}
