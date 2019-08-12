#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    //freopen("in.txt", "r", stdin);
    ll n1;
    ll n2;
    cin >> n1 >> n2; 
    ll g = __gcd(n1, n2); 
    int q;
    cin >> q;
    while(q--) {
        int x1,x2;
        ll y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1--;
        y2--;
        if(y1/(x1==1?n1/g:n2/g) == y2/(x2==1?n1/g:n2/g)) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}