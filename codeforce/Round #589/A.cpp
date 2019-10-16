#include<bits/stdc++.h>
#define LL long long
using namespace std;

bool check(int i) {
    int a[10];
    memset(a, 0, sizeof(a));
    while(i) {
        a[i % 10]++;
        i /= 10;
    }
    for(int i = 0; i < 10; i++) {
        if(a[i] >= 2) return false;
    }
    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    bool flag = false;
    for(int i = l; i <= r; i++) {
        if(check(i)) {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) {
        cout << -1 << endl;
    }
    return 0;
}