#include<bits/stdc++.h>
#define LL long long
using namespace std;

//自定义序列 不可重复

void printPermutation(int n, int cur, int* A, int* P) {
    if(cur == n) {
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < cur; j++) {
            if(P[i] == A[j]) {
                ok = false;
                false;
            }
        }
        if(ok) {
            A[cur] = P[i];
            printPermutation(n, cur + 1, A, P);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P[] = {1, 2, 3, 5, 6, 10};
    int A[10];
    printPermutation(6, 0, A, P);
    
    return 0;
}