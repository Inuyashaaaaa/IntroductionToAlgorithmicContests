#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e3 + 10;
int a[maxn];
int p[maxn]; //right
int q[maxn]; //left
int n;

bool check() {
    memset(p, -1, sizeof(p));
    memset(q, -1, sizeof(q));
  
    //寻找右边比他大的第一个数
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                p[i] = j;
                break;
            }
        }
    }
    //寻找左边比他小的第一个数
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(a[i] > a[j]) {
                q[i] = j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 3; j < n; j++) {
            if(a[i] > a[j]) continue;
            if(p[i] == -1 || q[j] == -1) continue;
            if(p[i] < q[j] && a[p[i]] > a[j] && a[q[j]] < a[i]) {
                //cout << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ok = false;
        if(check()) ok = true;
        reverse(a, a + n);
        if(check()) ok = true;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}