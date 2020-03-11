#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> odd;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                cout << 1 << endl;
                cout << i + 1 << endl;
                goto END;
            }
            if(a[i] % 2 == 1) {
                odd.push_back(i + 1);
            }
            if(odd.size() == 2) {
                cout << 2 << endl;
                cout << odd[0] << " " << odd[1] << endl;
                goto END;
            }
        }
        cout << -1 << endl;
        END: continue;
    }
    return 0;
}