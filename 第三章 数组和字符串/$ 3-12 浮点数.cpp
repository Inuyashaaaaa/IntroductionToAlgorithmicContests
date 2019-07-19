#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;
double M[15][50];
int E[15][50];

void process()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=30;j++)
		{
			double m = 1-pow(2,-1-i);
			double e = pow(2,j)-1;
			double t = log10(m)+e*log10(2);
			E[i][j] = t;
			M[i][j] = pow(10,t-E[i][j]);
		}
	}
}


int main()
{
	process();
//	for(int i=0;i<=9;i++)
//	{
//		for(int j=1;j<=30;j++)
//		{
//			cout<<E[i][j]<<" "<<M[i][j]<<endl;
//		}
//	}
	string s;
	while(cin>>s && s!="0e0")
	{
		for(string::iterator i =s.begin();i!=s.end();i++)
		if(*i=='e')
		*i=' ';
		double A;
		int B;
		istringstream ss(s);
		ss>>A>>B;
		if(A==0&&B==0)
		break;
		for(int i=0;i<=9;i++)
		{
			for(int j=1;j<=30;j++)
			{
				if(B==E[i][j] && fabs(A - M[i][j]) < 1e-4)
				{
					cout<<i<<' '<<j<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
