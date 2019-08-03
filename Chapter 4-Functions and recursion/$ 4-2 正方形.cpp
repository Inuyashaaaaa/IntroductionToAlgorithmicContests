#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 150
#define maxm 15
using namespace std;


int find1[15][15][2];

int n,m;

int calculate(int size)
{
	int cnt=0;
	for(int i=1;i<=n-size;i++)
	{
		for(int j=1;j<=n-size;j++)
		{
			int judge = 1;
			for(int k=1;k<=size;k++)
			{
				//H方向 以及 V方向 
				if(find1[i][j+k-1][0]!=1
				|| find1[i+size][j+k-1][0]!=1
				|| find1[j][i+k-1][1]!=1
				|| find1[j+size][i+k-1][1]!=1)
				 {
				 	judge = 0;
				 	break;
				 }			 
			}
			if(judge)
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("4-2.in","r",stdin);
	freopen("4-2.out","w",stdout);
	int cnt = 0;
	while(cin>>n>>m)
	{
		if(cnt++)
		{
			cout<<endl;
			cout<<"**********************************"<<endl;
			cout<<endl;
		}	
		
		memset(find1,0,sizeof(find1));
		for(int i=0;i<m;i++)
		{
			char type;
			int x,y;
			cin>>type>>x>>y;
			if(type=='H')
			find1[x][y][0]=1;
			else
			find1[x][y][1]=1;
		}
		int judge = 0;
		cout<<"Problem #"<<cnt<<endl;
		cout<<endl;	
		for(int i=1;i<n;i++)
		{
			int temp = calculate(i);
			if(temp)
			{
				cout<<temp<<" square (s) of size "<<i<<endl;
				judge=1;
			}
		}
		if(!judge)
		cout<<"No completed squares can be found."<<endl;
	}
} 
