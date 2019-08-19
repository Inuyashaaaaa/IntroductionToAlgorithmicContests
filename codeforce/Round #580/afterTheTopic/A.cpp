#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, x;
    int max1, max2;
    max1 = max2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        max1 = max(max1, x);
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        max2 = max(max2, x);
    }
    cout << max1 << " " << max2 << endl;
}