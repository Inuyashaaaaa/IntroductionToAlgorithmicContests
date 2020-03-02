#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;
int arr[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < a; i++) {
            cin >> arr[i];
        }
        int d = arr[0];
        for(int i = 1; i < a; i++) {
            int e = b % i;
            int value = min(arr[i] * i, b - e);
            b -= value;
            d += value / i;
            if(b <= i) {
                break;
            }
        }
        cout << d << endl;
    }
    return 0;
}