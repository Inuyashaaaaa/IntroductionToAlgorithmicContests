#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 6000 + 60;
int x[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(x, 0, sizeof(x));
    int firstX = maxn;
    for(int i = 0; i < n; i++) {
        int xL, h, xR;
        cin >> xL >> h >> xR;
        xL += 3000;
        xR += 3000;
        firstX = min(xL, firstX);
        for(int j = xL; j < xR; j++) {
            if(h > x[j]) x[j] = h;
        }
    }
    cout << firstX - 3000 <<  " " << x[firstX];
    for(int i = firstX; i < maxn; i++) {
        if(x[i] != x[i + 1]) {
            cout << " " << i - 2999 << " " << x[i + 1]; 
        }
    }
    
    return 0;
}