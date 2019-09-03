#include<bits/stdc++.h>
#define LL long long
using namespace std;

void printSubset(int n, int* B, int cur) {
    if(cur == n + 1) {
        for(int i = 1; i <= n; i++) 
            if(B[i]) cout << i << " ";
        cout << endl;
        return;
    }
    B[cur] = 1;
    printSubset(n, B, cur + 1);
    B[cur] = 0;
    printSubset(n, B, cur + 1);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int B[10];
    printSubset(10, B, 1);

    return 0;
}