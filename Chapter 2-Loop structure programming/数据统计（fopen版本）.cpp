#include<stdio.h>
#define INF 1e10
int main()
{
	FILE *fin, *fout;
	fin = fopen("input.txt","rb"); 
	fout = fopen("output.txt","wb");
	int x,n=0,min=INF,max=-INF,s=0;
	while(fscanf(fin,"%d",&x)==1)
	{
		s+=x;
		 
		if(x<min)min=x;
		if(x>max)max=x;
		n++;
	}
	fprintf(fout,"%d %d %.3f\n",min,max,(double)s/n);
	fclose(fin);
	fclose(fout);
	return 0;
}
