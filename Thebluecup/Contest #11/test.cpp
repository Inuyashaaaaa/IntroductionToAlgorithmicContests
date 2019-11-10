#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main(void)
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char bin[33] = { 0 };
    while(cin >> bin) {
	int a[33] = { 0 };
	int dec = 0, i = 0, c = 0;
	i = strlen(bin);
	c = i;
	for (int k = 0; k < c; k++)
	{	
		a[k] = bin[k] - 48;
		if (a[k] != 0 && a[k] != 1)
			return 0;
	}
	for (int k = 0; k<c; k++)
	{
		dec = dec + a[k]*pow(2, i-1);
		i--;
	}
	cout << dec << endl;
    }
	return 0;
}