#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
int n;

bool check(int u) {
    if(u == 1) return false;
    for(int i = 2; i * i <= u; i++) {
        if(u % i == 0) return false;
    }
    return true;
}

void solve(int d, int u) {
    if(d == n) {
        cout << u << endl;
        return;
    }
    for(int i = 1; i <= 9; i++) {
        if(check(u * 10 + i)) {
            solve(d + 1, u * 10 + i);
        } 
    }
}



int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n ;
    solve(0, 0);
    return 0;
}