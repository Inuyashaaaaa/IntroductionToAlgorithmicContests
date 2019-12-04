#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 3e2 + 10;
int a[maxn];
int n;

bool ok(int l) {
    for(int i = 0; i < n ;i++) {
        if(a[(i + l) % n] != i + 1) return false;
    }
    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n && n) {

        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 0;
        string s;
        while(!ok(l)) {
            if(a[l % n] > a[(l + 1) % n] && !(a[l % n] == n && a[(l + 1) % n] == 1)) {
                swap(a[l % n], a[(l + 1) % n]);
                s += '1';
            } else {
                l--;
                if(l < 0) l = n - 1;
                s += '2';
            }
        }
        //cout << s << endl;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}