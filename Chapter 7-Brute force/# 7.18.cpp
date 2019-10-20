#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define INF 0x7fffffff
using namespace std;
// 4 * 6
const int r = 4;
const int c = 6;
int maze[r * 2][c * 2];
// <- ↑ -> ↓
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const char w[] = {'W', 'N', 'E', 'S'};
const int rev[] = {2, 3, 0, 1};
vector<pair<int, int>> endVec;

int h(int x, int y) {
    int minn = INF;
    for(auto& pair: endVec) {
        //cout << "pair.first: " << pair.first << " pair.second: " << pair.second << endl;
        minn = min(abs(pair.first - x) + abs(pair.second - y), minn);
    }
    //cout << ">> " << minn << endl;
    return minn;
}

bool dfs(int x, int y, int d, int maxd, string way) {
    if(d == maxd) {
        //cout << way << endl;
        //cout << way << endl;
        if(x == 0 || y == 0 || x > r || y > c) {
            cout << way << endl;
            return true;
        }
        return false;
    }
    if(d + h(x, y) > maxd) return false;
    bool wall[4] = {0};
    for(int i = 0; i < 4; i++) {
        if(maze[x][y] & (1 << i)) wall[i] = true;
    }
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(wall[i]) {
            //双面墙
            if(maze[xx][yy] & (1 << i)) {
                continue;
            }
            //不能推墙到边界 也不能推边界墙
            //cout << "x: " << x << " y: " << y << endl;
            if(i == 0 && (y == 1)) continue;
            if(i == 1 && (x == 1)) continue;
            if(i == 2 && (y == 6)) continue;
            if(i == 3 && (x == 4)) continue; 
            //推墙
            //if(maze[xx][yy] & (1 << i)) continue;
            maze[x][y] ^= (1 << i);
            maze[xx][yy] ^= (1 << i);
            if(xx != 0 && yy != 0) {
                maze[xx + dx[i]][yy + dy[i]] ^= (1 << (rev[i]));
            }
            if(dfs(xx, yy, d + 1, maxd, way + w[i]))
            return true;
            maze[x][y] ^= (1 << i);
            maze[xx][yy] ^= (1 << i);
            if(xx != 0 && yy != 0) {
                maze[xx + dx[i]][yy + dy[i]] ^= (1 << (rev[i]));
            }
        } else {
            //cout << "x: " << x << " y: " << y << endl;
            if(dfs(xx, yy, d + 1, maxd, way + w[i]))
            return true;
        }
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int beginX, beginY;
    while(cin >> beginY >> beginX && beginX && beginY) {
        ms(maze);
        endVec.clear();
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cin >> maze[i][j];
                ///cout << maze[i][j];
                
                if(i == 1 && ((maze[i][j] & 2) == 0))
                endVec.push_back(make_pair(i, j));
                else if(i == 4 && ((maze[i][j] & 8) == 0))
                endVec.push_back(make_pair(i, j));
                else if(j == 1 && ((maze[i][j] & 1) == 0))
                endVec.push_back(make_pair(i, j));
                else if(j == 6 && ((maze[i][j] & 4) == 0))
                endVec.push_back(make_pair(i, j));
            }
        }
        //cout << maze[beginX][beginY];
        int maxd = 1;
        for(maxd; ;maxd++) {
            //cout << maxd << endl;
            if(dfs(beginX, beginY, 0, maxd, ""))
            break;
        }
    }
    return 0;
}