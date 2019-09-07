#include<bits/stdc++.h>
#define LL long long
using namespace std;

//sort 可重复 子序列

void printPermutation(int cur, int n, int* A, int* P) {
    if(n == cur) {
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    } 
    for(int i = 0; i < n; i++) {
        if(!i || P[i] != P[i - 1]) {
            int c1 = 0;
            int c2 = 0;
            //统计已经有的数量
            for(int j = 0; j < cur; j++) {
                if(A[j] == P[i]) c1++;
            }
            //统计总共数量
            for(int j = 0; j < n; j++) {
                if(P[j] == P[i]) c2++;
            }
            if(c1 < c2) {
                A[cur] = P[i];
                printPermutation(cur + 1, n, A, P);
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[10];
    int P[] = {1, 2, 3, 3, 5};
    printPermutation(0, 5, A, P);
    return 0;
}