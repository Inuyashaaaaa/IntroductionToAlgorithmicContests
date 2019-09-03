#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 326880 + 10;
int status[maxn][9];
int dist[maxn];
int flag[maxn];
unordered_set<int> vis;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

bool isVis(int x) {
    int ans = 0;
    for(int i = 0; i < 9; i++) {
        ans *= 10;
        ans += status[x][i];
    }
    if(vis.count(ans)) return false;
    vis.insert(ans);
    return true;
}

bool check(const int* s) {
    for(int i = 0; i < 9; i++) {
        if(s[i] != flag[i])  return false;
    }
    return true;
}

bool bfs(int& ans) {
    vis.clear();
    int front = 1; 
    int rear = 2;
    while(front < rear) {
        const int* s = status[front];
        if(check(s)) return ans = front;
        int z;
        for(int i = 0; i < 9; i++)
            if(!s[i]) {
                z = i;
                break;
            }
            // for(int j = 0; j < 9; j++) {
            //     cout << " " << s[j] << " ";
            //     if((j + 1) % 3 == 0 && j)
            //     cout << endl;
            // }
        int x = z / 3; 
        int y = z % 3;
        //cout << " (" << x << "," << y << ")" << endl;
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX < 0 || newY < 0 || newX >= 3 || newY >= 3)
            continue;
            int newZ = newX * 3 + newY;
            //cout << "(" << newX << "," << newY << ")" << endl;
            for(int i = 0; i < 9; i++) 
            status[rear][i] = s[i];
            status[rear][newZ] = 0;
            status[rear][z] = s[newZ];
            // for(int j = 0; j < 9; j++) {
            //     cout << s1[j] << " ";
            //     if((j + 1) % 3 == 0 && j)
            //     cout << endl;
            // }
            dist[rear] = dist[front] + 1;
            if(isVis(rear)) rear++;
        }
        front++;
    }
    return 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(status[1], 0, sizeof(status[1]));
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < 9; i++) cin >> status[1][i];
    for(int i = 0; i < 9; i++) cin >> flag[i];
    int ans;
    if(bfs(ans)) {
        cout << dist[ans] << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}