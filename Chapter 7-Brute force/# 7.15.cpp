#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 15 + 5;
char pic[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int r, c;
string maxc;

bool dfs(int x, int y, string s, int maxd, int d) {
    if(d == maxd) {
        int len1 = s.length();
        int len2 = maxc.length();
        if(len1 > len2 || (len1 == len2 && s > maxc)) {
            maxc = s;
        }
        return true;
    }
    bool flag = false;
    string temp = s;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
        if(pic[xx][yy] == '#') continue;
        if(vis[xx][yy]) continue;
        vis[xx][yy] = true;
        s += pic[xx][yy];
        if(dfs(xx, yy, s, maxd, d + 1)) flag = true;
        s = temp;
        vis[xx][yy] = false;
    }
    return flag;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> r >> c && r && c) {
        maxc = "";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> pic[i][j];
            }
        }
        int maxL = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pic[i][j] != '#') {
                    string s;
                    s += pic[i][j];
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = true;
                    for(maxL ; ;maxL++) {
                        if(!dfs(i, j, s, maxL, 0))
                        {
                            maxL--;
                            break;
                        }
                    }
                    
                }
            }
        }
        cout << maxc << endl;
    }
    return 0;
}