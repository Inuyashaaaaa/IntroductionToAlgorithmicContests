#include<bits/stdc++.h>
#define LL long long
using namespace std;
int a, b;

LL fib(int n) {
    if(n == 0) return a;
    if(n == 1) return b;
    return fib(n - 1) ^ fib(n - 2);
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> a >> b >> n;
        n %= 3;
        cout << fib(n) << endl;
    }
    return 0;
}