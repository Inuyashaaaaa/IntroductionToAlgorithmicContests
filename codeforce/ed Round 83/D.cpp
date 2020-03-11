#include<bits/stdc++.h>
#define LL long long
const int maxn = 2e5;
using namespace std;
const int MOD = 998244353;
 
LL _f_[maxn + 5];	//  阶乘 
LL _a_[maxn + 10];	//  乘法逆元 

LL _p_(LL x) {
	LL n = MOD - 2;
    LL res = 1;
	while(n > 0) {
	   if(n % 2 == 1)	
	   	 res = res * x % MOD;
	   x = x * x % MOD;
	   n >>= 1;
	}
	return res;	
}
 
void init() {
    _a_[0] = _a_[1] = 1;
    _f_[0] = _f_[1] = 1;
    for(int i = 2; i <= maxn + 5; i++) {
        _f_[i] = _f_[i - 1] * i % MOD;
		_a_[i] = _a_[i - 1] * _p_(i) % MOD;
    }
}
 
LL power(LL n, LL m) {
    LL ret = 1;
    while(m--) {
        ret *= n;
        ret %= MOD;
    }
    return ret;
}

// Cnm n在下面的
LL C(int n, int m) {
	if(n < 0 || m < 0 || n < m) return 0;
    return _f_[n] * _a_[n-m] % MOD * _a_[m] % MOD;
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	LL ans,T, n, m;
	init();
    cin >> n >> m;
    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }
    ans = C(m, n - 1) % MOD * (n - 2) % MOD * power(2, n - 3);
    cout << ans % MOD << endl;
	return 0;
}