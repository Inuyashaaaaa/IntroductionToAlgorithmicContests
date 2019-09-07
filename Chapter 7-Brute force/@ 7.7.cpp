#include<bits/stdc++.h>
#define LL long long
using namespace std;

void printSubset(int cur, int n, int* A) {
    for(int i = 0; i < cur; i++) cout << A[i] << " ";
    cout << endl;
    int s = cur ? A[cur - 1] + 1 : 0;
    for(int i = s; i < n; i++) {
        A[cur] = i;
        printSubset(cur + 1, n, A);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[10];
    int n = 5;
    printSubset(0, n, A);
    return 0;
}