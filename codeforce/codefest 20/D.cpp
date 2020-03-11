#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
pair<int, int> G[maxn][maxn];
bool vis[maxn][maxn];
char pic[maxn][maxn];
int n;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
char ch[] = {'U', 'R', 'L', 'D'};

void dfs(int x, int y, int a, int b) {
    int xx, yy;
    for(int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
        if(G[xx][yy].first == a && G[xx][yy].second == b && !vis[xx][yy]) {
            vis[xx][yy] = true;
            pic[xx][yy] = ch[3 - i];
            dfs(xx, yy, a, b);
        }
    }
}

void dfs2(int x, int y, bool begin) {
    int xx, yy;
    for(int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
        if(G[xx][yy].first == -1 && G[xx][yy].second == -1 && !vis[xx][yy]) {
            if(begin) {
                pic[x][y] = ch[i];
                vis[x][y] = true;
            }
            pic[xx][yy] = ch[3 - i];
            vis[xx][yy] = true;
            dfs2(xx, yy, 0);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int a, b;
            cin >> a >> b;
            G[i][j] = make_pair(a, b);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == G[i][j].first && j == G[i][j].second && !vis[i][j]) {
                pic[i][j] = 'X';
                vis[i][j] = true;
                dfs(i, j, i, j);
            }
            if(G[i][j].first == -1 && G[i][j].second == -1 && !vis[i][j]) {
                dfs2(i, j, true);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vis[i][j]) {
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }
    cout << "VALID" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << pic[i][j];
        }
        cout << endl;
    }

    return 0;
}