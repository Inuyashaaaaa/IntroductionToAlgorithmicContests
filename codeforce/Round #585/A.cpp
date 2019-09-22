#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    
    //max
    if(k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }
    int maxn = 0;
    int num = n / k1;
    if(num > a1) {
        maxn = a1;
        n -= a1 * k1;
        maxn += min(n / k2, a2);
        n += a1 * k1;
    } else {
        maxn = num;
    }

    //min 
    int minn;
    num = a1 * k1 + a2 * k2;
    num -= n;
    if(num <= 0) {
        minn = a1 + a2;
    } else {
        minn = max(0, (a1 + a2) - num);
    }

    cout << minn << " " << maxn << endl;

    return 0;
}