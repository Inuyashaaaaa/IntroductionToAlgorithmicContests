#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 110 + 5;
int block[2 * maxn][2 * maxn];
bool vis[2 * maxn][2 * maxn];
int way[30]; //路径
int dx[] = {1, 0, 0, -1};  // ->  ↑ ↓ <-
int dy[] = {0, 1, -1, 0};
char w[] = "ensw";
int cnt;

bool check(int xb, int xe, int yb, int ye) {
    if(xb == xe) {
        if(ye < yb) {
            swap(ye, yb);        
        }
        for(int i = yb; i <= ye; i++) {
            if(block[xb][i]) {
                //cout << xb - maxn << "*" << i - maxn << endl;
                return false;
            }
        }
    }
    else {
        if(xe < xb) {
            swap(xe, xb);   
        }
        for(int i = xb; i <= xe; i++) {
            if(block[i][yb]) {
                //cout << i - maxn << "*" << yb - maxn << endl;
                return false;
            }

        }
    }
    // if(w[way[0]] == 'n' && w[way[1]] == 'w') {
    //     cout << xb  << " " << xe  << " " << yb  << " " << ye  << endl;
    //     cout << block[xb][115] << endl;
    // }
    return true;
}

void dfs(int d, int maxd, int dir, int x, int y) {
    if(d == maxd) {
        if(x != maxn || y != maxn) return;
        for(int i = 0; i < maxd; i++) {
            cout << w[way[i]];        
        }
        cout << endl;
        cnt++;
        return;
    }
    if(abs(x - d) - maxn  > ((d + maxd) * (maxd - d)) / 4) return;
    int xx, yy;
    for(int i = 0; i < 4; i++) {
        xx = x + (d + 1) * dx[i];
        yy = y + (d + 1) * dy[i];
        if(vis[xx][yy]) continue;
        if(!check(x, xx, y, yy)) continue;
        if(dir == -1) {
            way[d] = i;
            vis[xx][yy] = true;
            dfs(d + 1, maxd, i, xx, yy);
            vis[xx][yy] = false;
        } 
        else if((dir == 0 || dir == 3) && (i == 1 || i == 2)) {
            way[d] = i;
            vis[xx][yy] = true;
            dfs(d + 1, maxd, i, xx, yy);
            vis[xx][yy] = false;
        }
        else if((dir == 1 || dir == 2) && (i == 0 || i == 3)) {
            way[d] = i;
            vis[xx][yy] = true;
            dfs(d + 1, maxd, i, xx, yy);
            vis[xx][yy] = false;
        }
    }

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cnt = 0;
        memset(block, 0, sizeof(block));
        memset(vis, 0, sizeof(vis));
        int maxd;
        cin >> maxd;
        int n;
        cin >> n;
        int a, b;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            block[a + maxn][b + maxn] = 1;
            //cout << "b:" << a + maxn << " " << b + maxn << endl;
        }
        dfs(0, maxd, -1, maxn, maxn);
        cout << "Found " << cnt << " golygon(s)." << endl;
        cout << endl;
    }
    return 0;
}