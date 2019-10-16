#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 15, maxm = 6;
const int dir[maxn][maxm] = {
    { -1, -1, -1, -1,  1,  2} , { -1,  0, -1,  2,  3,  4} , {  0, -1,  1, -1,  4,  5},
    { -1,  1, -1,  4,  6,  7} , {  1,  2,  3,  5,  7,  8} , {  2, -1,  4, -1,  8,  9},
    { -1,  3, -1,  7, 10, 11} , {  3,  4,  6,  8, 11, 12} , {  4,  5,  7,  9, 12, 13},
    {  5, -1,  8, -1, 13, 14} , { -1,  6, -1, 11, -1, -1} , {  6,  7, 10, 12, -1, -1},
    {  7,  8, 11, 13, -1, -1} , {  8,  9, 12, 14, -1, -1} , {  9, -1, 13, -1, -1, -1}
};

struct Node {
    int state;
    Node* parent;
};

int n;
int state;
bool vis[32768]; //判重

void printAns(Node* cur, Node* parent) {

}

void bfs() {
    queue<Node*> q;
    Node* root = new Node();
    root->parent = NULL;
    root->state = state;
    q.push(root);
    while(!q.empty()) {
        //15个洞
        Node* nn = q.front();
        if(nn->state == (1 << (n - 1))) {
            printAns(nn, nn->parent);
            return;
        }
        q.pop();
        int state = nn->state;
        for(int i = 0; i < 15; i++) {
            //判断洞是否有球球
            if((state & (1 << i)) != 0) continue; //没球
            for(int j = 0; j < 6;j ++) {
                //六个方向走
                int step = 0;
                //走的位置有球
                while(dir[i][j] && (state & (1 << i))) {
                    i = dir[i][j];
                    step++;
                }
                //有球 因为-1出来的
                if(state & (1 << i)) continue;
                //没球 如果step = 1 没用
                if(step == 1) continue;
                while(dir[i][j] & (state & (1 << i))) {
                    state ^= (1 << (i - 1));
                    i = dir[i][j];
                }
                state |= (1 << (i - 1));
                if(vis[state]) continue;
                vis[state] = 1;
                Node* n1 = new Node();
                n1->parent = nn;
                n1->state = state;
                q.push(n1); 
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        state = 32767; // 0111 1111 1111 1111
        state ^= (1 << (n - 1));
        memset(vis, 0, sizeof(vis));
        vis[state] = 1;
        bfs();
    }
    return 0;
}