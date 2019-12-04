#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 4e5 + 10;

int _left[maxn];
int _right[maxn];
int value[maxn];
int n, m;

int solve(int k) {
    for(int i = 1; i <= m; i++) {
        value[i] = !((_left[i] < 0 ? -_left[i] > k : value[_left[i]])
        & (_right[i] < 0 ? -_right[i] > k : value[_right[i]]));
    }
    return value[m];
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            cin >> _left[i] >> _right[i];
        }
        int v1 = solve(0);
        int v2 = solve(n);
        if(v1 == v2) {
            for(int i = 0; i < n; i++) {
                cout << "0";
            }
            cout << endl;
        }
        else {
            int l = 1;
            int r = n;
            //[l, r]
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(solve(mid) == v1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            for(int i = 1; i < l; i++) cout << "0";
            cout << "x";
            for(int i = l + 1; i <= n; i++) cout << "1";
            cout << endl;
        }
    }
    return 0;
}
