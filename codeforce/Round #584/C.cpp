#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
int vis[maxn];
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        sort(a, a + n);
        int cnt = 0;
        // for(int i = 0; i < n; i++) {
        //     cout << a[i] << ' ';
        // }
        vector<int> pos1;
        for(int i = 0; i < n; i++) {
            if(a[cnt] == s[i] - '0' && !vis[i]) {
                cnt++;   
                vis[i] = 1;
            }
            if(cnt == n) {
                    break;
            }
        }
        if(cnt != n) {
            for(int i = 0; i < n; i++) {
                if(a[cnt] == s[i] - '0' && !vis[i]) {
                    cnt++;
                    vis[i] = 2;
                }
                if(cnt == n) {
                    break;
                }
            }
        }
        if(cnt == n) {
            for(int i = 0; i < n; i++) {
                cout << vis[i];
            }
            cout << endl;
        } else {
            cout << "-" << endl;
        }
    }
    return 0;
}