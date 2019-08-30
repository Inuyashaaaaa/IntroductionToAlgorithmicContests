#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[100];
    int odd, even;
    odd = even = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0)
        even++;
        else 
        odd++;
    }
    cout << min(even, odd) << endl;

    return 0;
}