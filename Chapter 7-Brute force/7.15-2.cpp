#include<bits/stdc++.h>
#define LL long long
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
const int maxn = 15 + 4;

struct Node {
    int x, y;
};

int r, c;
string ans;
char pic[maxn][maxn];
bool vis[maxn][maxn];

void update(const string &s) {
    int len1 = ans.size();
    int len2 = s.size();
    if((len1 < len2) || (len1 == len2 && s > ans)) {
        ans = s;
    }
}

int h(int x, int y) {
    bool vv[maxn][maxn];
    memcpy(vv, vis, sizeof(vis));
    Node root;
    root.x = x;
    root.y = y;
    vv[x][y] = true;
    int depth = 0;
    queue<Node> q;
    q.push(root);
    while(!q.empty()) {
        Node n = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = n.x + dx[i];
            int yy = n.y + dy[i];
            if(xx < 0 || xx >= r || yy < 0 || yy >=c ) continue;
            if(pic[xx][yy] == '#' || vv[xx][yy]) continue;
            Node n1;
            n1.x = xx;
            n1.y = yy;
            depth++;
            vv[xx][yy] = true;
            q.push(n1);
        }
    }
    return depth;
}

void dfs(int x, int y, string s, int d) {
    int l = h(x, y);
    if(l + d < ans.size())  return;
    if(l + d == ans.size() && (s + "z") < ans) return;
    update(s);
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
        if(pic[xx][yy] == '#' || vis[xx][yy]) continue;
        vis[xx][yy] = 1;
        dfs(xx, yy, s + pic[xx][yy], d + 1);
        vis[xx][yy] = 0;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> r >> c && r && c) {
        ans = "";
        for(int i = 0; i < r; i++)
            cin >> pic[i];
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pic[i][j] != '#') {
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = 1;
                    string s;
                    s += pic[i][j];
                    dfs(i, j, s, 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}