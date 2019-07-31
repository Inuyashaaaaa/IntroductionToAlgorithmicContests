#include<iostream>
using namespace std;

unsigned long long pofs,qofs;
int Amin,Bmin;

int main()
{
	unsigned long long N,SP,SQ;
	while(cin>>N>>SP>>SQ)
	{
		pofs = (N-1) * SP;
		unsigned long long minn = 0xffffffffffffffff;
		for(int A=0;A<32;A++)
		{
			for(int B=0;B<32;B++)
			{
				qofs = (pofs + (pofs << A) >> B) + SQ;
				if(qofs >= N * SQ && qofs < minn)
				{
					minn = qofs;
					Amin = A;
					Bmin = B;
				}
			}
		}
		cout << minn << " " << Amin << " "<< Bmin << endl;
	}
	return 0;
} 
