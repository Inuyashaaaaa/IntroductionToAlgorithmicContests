#include<bits/stdc++.h>
#define  LL long long

using namespace std;
const int maxn = 1e5 + 5;

LL a[maxn + maxn];
LL b[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int t = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1) {
            a[i] = t + 1;
            a[i + n] = t + 2;
            t += 2;
        }
        else{
            a[i] = t + 2;
            a[i + n] = t + 1;
            t += 2;
        }
    }
    for(int i = 1;i <= n*2; i++) 
    cout << a[i] << " ";
    cout << endl;
}
