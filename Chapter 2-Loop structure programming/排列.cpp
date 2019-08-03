#include<stdio.h>
int getT(int n)
{
	return n/100;
}

int getS(int n)
{
	return n/10%10;
}

int getF(int n)
{
	return n%10;
}

int main()
{
	for(int i=123;i<987/3;i++)
	{
		int judge=1;
		int use[10];
		for(int j=1;j<10;j++)
		use[j]=1;
		use[getF(i)]=0;
		use[getS(i)]=0;
		use[getT(i)]=0;
		use[getF(i*2)]=0;
		use[getS(i*2)]=0;
		use[getT(i*2)]=0;
		use[getF(i*3)]=0;
		use[getS(i*3)]=0;
		use[getT(i*3)]=0;
		for(int j=1;j<10;j++)
		if(use[j]==1)
		{
			judge=0;
			break;
		}
		if(judge)
		printf("%d %d %d\n",i,i*2,i*3);
	}
	return 0;
} 

