#include<bits/stdc++.h>
#define LL long long
using namespace std;

//STL next_permutation

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[] = {2, 1, 1, 1};
    sort(A, A + 4);
    do {
        for(int i = 0; i < 4; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }while(next_permutation(A, A + 4));   
    return 0;
}