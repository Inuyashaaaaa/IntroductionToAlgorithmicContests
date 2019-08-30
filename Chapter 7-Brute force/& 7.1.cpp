#include<bits/stdc++.h>
using namespace std;

void printPermutation(int n, int* A, int cur) {
    if(cur == n) {
        for(int i = 0; i < n ; i++)
        cout<< A[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < cur; j++) {
            if(i == A[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            A[cur] = i;
            printPermutation(n, A, cur + 1);
        }

    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n = 6;
    int A[6];
    printPermutation(n, A, 0);
    return 0;
}