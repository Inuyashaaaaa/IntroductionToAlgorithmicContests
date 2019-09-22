#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxAns = 13; //实验
int a[14];
int n;

bool dfs(int d, int maxd) {
    if(a[d] == n) return true;
    if(d == maxd) return false;
    int maxn = 0;
    for(int i = 0; i <= d; i++) {
        maxn = max(maxn, a[i]);
    }
    if((maxn << (maxd - d)) < n) return false;
    for(int i = d; i >= 0; i--) {
        a[d + 1] = a[d] + a[i];  
        if (dfs(d + 1, maxd)) return true;
        a[d + 1] = a[d] - a[i];
        if (dfs(d + 1, maxd)) return true;
    }
    return false;
}

int solve() {
    if(a[0] == n) return 0;
    for(int maxd = 1; maxd < 13; maxd++) {
        if(dfs(0, maxd)) return maxd;
    }
    return maxAns;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0] = 1;
    while(cin >> n && n) {
        cout << solve() << endl;
    }
    return 0;
}