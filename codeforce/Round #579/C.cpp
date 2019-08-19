#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 4e5 + 1000;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt" , "w", stdout);
    long long n;
    cin >> n;
    long long g ;
    cin >> g;
    long long x;
    for(long long i = 2; i <= n; i++) {
        cin >> x;
        g = __gcd(x,g);
    }
    long long cnt = 0;
    for(long long i=1;i<=sqrt(g);i++){
        if(g % i ==0){
        if(i*i==g) cnt++;
        else
        cnt+=2;
        }
    }
    cout << cnt << endl;
    return 0;
}