#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 4e2 + 10;
int g[maxn][maxn];
bool vis[maxn][maxn];
struct Node {
    int x, y;
};

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, ENT, EXIT;
    cin >> r >> c >> ENT >> EXIT;
    memset(g, 1, sizeof(g));
    ms(vis);
    for(int i = 1; i <= 2 * r - 1; i++) {
        for(int j = 1; j <= (i % 2 == 0 ? c : c - 1); j++) {
            cin >> g[i][j];
        }
    }
    queue<Node> q;
    Node n;
    n.x = 1;
    n.y = ENT;
    q.push(n);
    vis[n.x][n.y] = true;
    int step = 0;
    bool flag = false;
    while(!q.empty()) {
        step++;
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            Node n1 = q.front();
            q.pop();
            //cout << n1.x << " " << n1.y << endl;
            if(n1.x == 2 * r - 1 && n1.y == EXIT) {
                flag = true;
                break;
            }
            // left
            if(g[n1.x][n1.y - 1] == 0 && !vis[n1.x][n1.y - 1]) {
                Node temp = n1;
                temp.y--;
                q.push(temp);
                vis[n1.x][n1.y - 1] = 1;
            }
            // right
            if(g[n1.x][n1.y] == 0 && !vis[n1.x][n1.y + 1]) {
                Node temp = n1;
                temp.y++;
                q.push(temp);
                vis[n1.x][n1.y + 1] = 1;
            }
            // top
            if(g[n1.x - 1][n1.y] == 0 && !vis[n1.x - 2][n1.y]) {
                Node temp = n1;
                temp.x -=2;
                q.push(temp);
                vis[n1.x - 2][n1.y] = 1;
            }
            // bot
            if(g[n1.x + 1][n1.y] == 0 && !vis[n1.x + 2][n1.y]) {
                Node temp = n1;
                temp.x +=2;
                q.push(temp);
                vis[n1.x + 2][n1.y] = 1;
            }
        }
        //cout << endl;
        if(flag) break;
    }
    if(flag) cout << step + 1 << endl;
    else cout << "No Way" << endl;


    return 0;
}