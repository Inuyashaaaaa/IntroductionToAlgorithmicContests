#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#define ll long long
#define MAXN 1000000 + 5
using namespace std;
int INF = 0x7fffffff;
 
int main(){
    int t;
    ll k, m, n;
    cin >> t;
    string a, b;
    while(t--) {
        cin >> a >> b;
        int i, j;
        int tt=0, tz=0;
 
        for(i = b.length()-1; i>=0; i--){
            if(b[i]=='1') break;
            tt++;
        }
 
        for(j = a.length()-1-tt,tz=0; j>=0; j--){
            if(a[j]=='1') break;
            tz++;
        }
        cout << tz << endl;
    }
    return 0;
}