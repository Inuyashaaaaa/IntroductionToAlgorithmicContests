#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxAns = 13;
int n;
int a[14];

bool dfs(int d, int maxd) {
    if(a[d] == n) return true;
    if(d == maxd) return false;
    int maxdd = a[0];
    for(int i = 1; i <= d; i++) 
        maxdd = max(maxdd, a[i]);
    if ((maxdd << (maxd - d)) < n) return false;
    for(int i = d; i >= 0; i--) {
        a[d + 1] = a[d] + a[i];
        if(dfs(d + 1, maxd)) return true;
        a[d + 1] = a[d] - a[i];
        if(dfs(d + 1, maxd)) return true;
    }
    return false;
}

int solve() {
    if(n == a[0]) return 0;
    for(int maxd = 1; maxd < maxAns; maxd++) 
        if(dfs(0, maxd)) return maxd;
    return maxAns;    
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0] = 1;
    while(cin >> n && n) {
        cout << solve() << endl;
    }    
    return 0;
}