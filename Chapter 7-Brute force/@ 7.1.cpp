#include<bits/stdc++.h>
#define LL long long
using namespace std;

void printPermutation(int n, int* A, int cur) {
    if(cur == n) {
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 0; j < cur; j++) {
            if(A[j] == i) {
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[10];
    printPermutation(6, A, 0);
    return 0;
}