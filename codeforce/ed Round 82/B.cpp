#include <bits/stdc++.h>
#define  ll long long
using namespace std;
const int MAXN=2e5+5;

int main(){
    ll n,t;
    ll a,b,c;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        ll m=n;
        if(n%2) n=n/2+1;
        else n/=2;
        ll t=n/a;
        ll  ans=0;
        if(n%a==0)
            ans=(t-1)*(a+b)+a;
        else
            ans=(t)*(a+b)+n%(a);
        if(ans<m) cout<<m<<endl;
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}