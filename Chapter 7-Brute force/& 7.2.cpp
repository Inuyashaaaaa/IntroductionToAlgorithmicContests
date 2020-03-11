#include<bits/stdc++.h>
#define LL long long;
using namespace std;

void printPermutation(int n, int* A, int cur, int* P) {
    if(cur == n) {
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        int c1, c2;
        c1 = c2 = 0;
        if(!i || P[i] != P[i-1]) {
            for(int j = 0; j < n; j++) {
                if(P[i] == P[j])
                c1 ++;
            }
            for(int j = 0; j < cur; j++) {
                if(A[j] == P[i]) {
                    c2 ++;
                }
            }
            if(c2 < c1) {
                A[cur] = P[i];
                printPermutation(n, A, cur + 1, P);
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 3;
    int A[3];
    int P[3] = {1, 2, 4};
    printPermutation(3, A, 0, P);

    return 0;
}