#include<iostream>
#include<algorithm>
using namespace std;

bool judge(int k,char* s1,char*s2)
{
	for(int i=0;s1[k+i]&&s2[i];i++)
		if(s1[k+i]=='2'&&s2[i]=='2')
		return false;
	return true;
}

int process(char* s1,char*s2)
{
	int index=0;
	while(!judge(index,s1,s2))index++;
	return max(strlen(s1),strlen(s2)+index); 
} 

int main()
{
	char s1[105],s2[105];
	while(cin>>s1>>s2)
		cout<<min(process(s1,s2),process(s2,s1))<<endl;
	return 0;
}
