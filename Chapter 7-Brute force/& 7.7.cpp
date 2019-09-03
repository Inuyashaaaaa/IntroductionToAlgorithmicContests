#include<bits/stdc++.h>
#define LL long long
using namespace std;

void printSubset(int n, int s) {
    for(int i = 0; i < n; i++) {
        if(s & (1 << i)) cout << i << " ";
    }
    cout << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 10;
    for(int i = 0; i < (1<<n); i++) {
        printSubset(n, i);
    }
    return 0;
}