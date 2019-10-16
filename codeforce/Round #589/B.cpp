#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e3 + 10;
const LL mod = 1e9+7;
int vis[maxn][maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < h; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            vis[i][j] = 1;
        }
        vis[i][x] = 2;
    }
    for(int i = 0; i < w; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            if(vis[j][i] == 2) {
                cout << 0 << endl;
                return 0;
            }
            vis[j][i] = 1;
        }
        if(vis[x][i] == 1) {
            cout << 0 << endl;
            return 0;
        }
        vis[x][i] = 2;
    }
    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         cout << vis[i][j];
    //     }
    //     cout << endl;
    // }
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(vis[i][j] == 0) cnt++;
        }
    }
    LL ans = 1;
    for(int i = 0; i < cnt; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}