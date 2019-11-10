#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 10 + 4;
const int maxQ = 2.5e5 + 10;
int a[maxn];
bool ok[maxQ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxT = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(__gcd(a[i], a[j]) == 1) {
                maxT = max(a[i] * a[j] - a[i] - a[j] , maxT);
            }
        }
    }

    ms(ok);
    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= maxT; j += a[i]) {
            ok[j] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= maxT; j+= a[i]) {
            for(int k = 1; k <= maxT; k++) {
                if(ok[k]) {
                    ok[k + j] = true;
                }
            }
        }
    }
    for(int i = maxT; i >= 1; i--) {
        if(!ok[i]) {
            cout << i << endl;
            return 0;
        } 
    }
    cout << 0 << endl;
    return 0;
}