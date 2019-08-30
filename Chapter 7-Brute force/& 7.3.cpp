#include<bits/stdc++.h>
#define LL long long
using namespace std;

double fun(int n) {
    double ret = 1;
    for(int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    double k = 0;
    
    for(int i = 0; i < 100 ;i++) {
        k += 1 / fun(i);
        cout << fixed << setprecision(16) << k << endl;
    }
    return 0;
}