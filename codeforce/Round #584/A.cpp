#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[200];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 0;i < n; i++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        if(a[i]) {
            for(int j = i; j <= 100; j++) {
                if(a[j] && j % i == 0) {
                    a[j] = 0;
                }
            }
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}