#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#define TESTNUM 20
#define MAXN 100
#define MAXM 200
#define COLOR 10
using namespace std;
int main () {
	freopen("in.txt","w",stdout); 
	srand ( (unsigned int) time(NULL) );
	//code here
	int testnum=TESTNUM;
	while (testnum--) {
		int colornum=rand()%COLOR+2;
		int n=rand()%MAXN + 2;
		int m=rand()%MAXM +3;
		cout<<n<<" "<<m<<endl;
		int t1=1, t2=2;
		while (t2<n) {
			if (m==1) {
				cout<<t1<<" "<<n<<" "<<rand()%colornum<<endl;
				--m;
				break;
			}
			t2=rand()%(n-t1)+t1+1;
			cout<<t1<<" "<<t2<<" "<<rand()%colornum<<endl;
			--m;
			t1=t2;
		}
		for (int i=1; i<=m; ++i) {
			cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%colornum<<endl;
		}
		cout<<endl;
	}
	return 0;
}