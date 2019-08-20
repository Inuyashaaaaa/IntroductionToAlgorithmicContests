#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
char pic[maxn][maxn];
int idx[maxn][maxn];
int n, m;

void dfs(int index,int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m) return;
    if(idx[r][c] || pic[r][c] == '*') return;
    idx[r][c] = index;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <=1; dy++) {
            if(dx == 0 && dy == 0)
            continue;
            dfs(index, r + dx, c + dy);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n >> m && n) {
        memset(idx, 0, sizeof(idx));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> pic[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pic[i][j] == '@' && !idx[i][j])
                dfs(++cnt, i, j);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}