#include<iostream>
#define N 500001

using namespace std;

int parent[5];
int find(int n){
    if(n!=parent[n]) 
		parent[n]=find(parent[n]);
    return parent[n];
}

int main()
{
    freopen("out.txt", "w", stdout);
    parent[0] = 3;
    parent[1] = 2;
    parent[2] = 1;
    parent[3] = 9;
    pair<int,int> p;
    

    cout << find(2) << endl;
    cout << parent[0] << " " << parent[1] << " ";
    cout << parent[2] << " " << parent[3] << " ";
    return 0;
}
