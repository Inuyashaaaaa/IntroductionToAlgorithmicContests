#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 5;
    int A[5] = {1, 1, 1, 6, 7};
    sort(A, A + n);
    do{
        for(int i = 0; i < n; i++) 
        cout << A[i] << " ";
        cout << endl;
    }while(next_permutation(A, A + n));
    return 0;
}