#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
LL fac[2000];
const int P = 1e9 + 7;

void cal(){  
    fac[0]=1;  
    for(int i=1;i < 2000;i++) fac[i]=fac[i-1]*i%P;  
}  
  
inline LL qpow(LL a,LL b){  
    LL ans=1;  
    for(;b;b>>=1,a=a*a%P) if(b&1) ans=ans*a%P;
    return ans;  
}  
  
inline LL C(LL n,LL m){  
    if(n<m) return 0;  
    return fac[n]*qpow(fac[n-m]*fac[m]%P,P-2)%P;  
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n,m;
    cin>>n>>m;
    cal();
    cout<<C(2*m + n-1,2*m)<<endl;
    return 0;
}