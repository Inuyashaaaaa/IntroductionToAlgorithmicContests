#include<bits/stdc++.h>
#define LL long long
using namespace std;

int s[3], t[3];
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {1, 0, -1, 0, 0};
int deg[300];
int G[300][300];

struct Node {
    int c1, c2, c3; 
};
inline bool confict(int a1, int b1, int a2, int b2) {
    return a2 == b2 || (a1 == b2 && b1 == a2);
}
int d1[300][300][300];
int d2[300][300][300];
int bfs() {
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    queue<Node> q;
    queue<Node> eQ;
    Node begin;
    Node end;
    begin.c1 = s[0];
    begin.c2 = s[1];
    begin.c3 = s[2];
    end.c1 = t[0];
    end.c2 = t[1];
    end.c3 = t[2];
    q.push(begin);
    eQ.push(end);
    d1[s[0]][s[1]][s[2]] = 0;
    d2[t[0]][t[1]][t[2]] = 0;
    while(!q.empty() || !eQ.empty()) {
        int size = q.size();

        while(size--) {
            Node n = q.front();
            q.pop();
            int c1 = n.c1;
            int c2 = n.c2;
            int c3 = n.c3;
            for(int i = 0; i < deg[c1]; i++) {
                int c11 = G[c1][i];
                for(int j = 0; j < deg[c2]; j++) {
                    int c21 = G[c2][j];
                    if(confict(c1, c2, c11, c21)) continue;
                    for(int z = 0; z < deg[c3]; z++) {
                        int c31 = G[c3][z];
                        if(confict(c1, c3, c11, c31)) continue;
                        if(confict(c2, c3, c21, c31)) continue;
                        if(d1[c11][c21][c31] != -1) continue;
                        if(d2[c11][c21][c31] != -1) return d1[c1][c2][c3] + d2[c11][c21][c31] + 1;
                        Node nn;
                        nn.c1 = c11; nn.c2 = c21; nn.c3 = c31;
                        d1[c11][c21][c31] = d1[c1][c2][c3] + 1;
                        q.push(nn);
                    }
                }
            }
        }
        size = eQ.size();
        while(size--){
            Node n = eQ.front();
            eQ.pop();
            int c1 = n.c1;
            int c2 = n.c2;
            int c3 = n.c3;
            for(int i = 0; i < deg[c1]; i++) {
                int c11 = G[c1][i];
                for(int j = 0; j < deg[c2]; j++) {
                    int c21 = G[c2][j];
                    if(confict(c1, c2, c11, c21)) continue;
                    for(int z = 0; z < deg[c3]; z++) {
                        int c31 = G[c3][z];
                        if(confict(c1, c3, c11, c31)) continue;
                        if(confict(c2, c3, c21, c31)) continue;
                        if(d2[c11][c21][c31] != -1) continue;
                        if(d1[c11][c21][c31] != -1) return d1[c11][c21][c31] + d2[c1][c2][c3] + 1;
                        Node nn;
                        nn.c1 = c11; nn.c2 = c21; nn.c3 = c31;
                        d2[c11][c21][c31] = d2[c1][c2][c3] + 1;
                        eQ.push(nn);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, n;
    while(cin >> r >> c >> n && n) {
        memset(deg, 0, sizeof(deg));
        memset(G, 0, sizeof(G));
        string maze[20];
        cin.get();
        for(int i = 0; i < c; i++) 
            getline(cin, maze[i]);        
        int cnt = 0; 
        int x[300], y[300], m[20][20]; 
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                if(maze[i][j] != '#') {
                    x[cnt] = i;
                    y[cnt] = j;
                    m[i][j] = cnt;
                    if(islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt;
                    if(isupper(maze[i][j])) t[maze[i][j] - 'A'] = cnt;
                    cnt++;
                }
            }
        }
        for(int i = 0; i < cnt; i++) {
            int x1 = x[i];
            int y1 = y[i];
            deg[i] = 0;
            for(int j = 0; j < 5; j++) {
                int nx = x1 + dx[j];
                int ny = y1 + dy[j];
                if(maze[nx][ny] != '#') 
                    G[i][deg[i]++] = m[nx][ny];          
            }
        }
        if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++;}
        if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++; }
        cout << bfs() << endl;
    }
    return 0;
}