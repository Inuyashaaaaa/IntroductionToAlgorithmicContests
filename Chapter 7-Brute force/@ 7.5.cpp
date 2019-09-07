#include<bits/stdc++.h>
#define LL long long
using namespace std;

//位向量 printSubset

void printSubset(int cur, int* A, int n) {
    if(cur == n + 1) {
       for(int i = 1; i <= cur; i++) {
           if(A[i]) cout << i << " ";
       }
       cout << endl;
       return; 
    }
    A[cur] = 1;
    printSubset(cur + 1, A, n);
    A[cur] = 0;
    printSubset(cur + 1, A, n);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[10];
    memset(A, 0, sizeof(A));
    printSubset(1, A, 5);
    return 0;
}