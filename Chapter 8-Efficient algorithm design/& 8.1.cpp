#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
int len[maxn];
int vis[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        if(kase++) cout << endl;
        int n;
        cin >> n;
        int max1;
        cin >> max1;
        for(int i = 0; i < n; i++) {
            cin >> len[i];
        }
        sort(len, len + n);
        //当前位置
        ms(vis);
        int ans = 0;
        int j = n - 1;
        int i = 0;
        while(i < j) {
            if(len[i] + len[j] <= max1) {
                vis[i] = vis[j] = 1;
                i++;
                j--;
                ans++;
            } else {
                j--;
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}