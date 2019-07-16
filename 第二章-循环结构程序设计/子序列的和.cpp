#include<stdio.h>
int main()
{
	int n,m;
	int kase=0;
	while(scanf("%d%d",&n,&m)==2)
	{	
		if(m==0 && n==0)
		break;
		
		kase++;
		double s=0;
		for(double i=n;i<=m;i++)
		{
			s+=1/(i*i);//若使用int i 改为1.0/（i*i) 会造成乘法溢出 
		}
		printf("Case %d: %.5f\n",kase,s);
	}
	return 0;
}
