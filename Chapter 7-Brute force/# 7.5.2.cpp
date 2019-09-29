#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 200 + 10;
const int maxr = 5;

int maze[maxr][maxn];
int x[maxn], y[maxn];
int n;
char str[maxn];
int cnt;
int res;
vector<int> store;

void init() {  
    res = n * 9;
    store.clear();
    cnt = 0;
    memset(maze, 0, sizeof(maze));
    for(int i = 0; i < 5; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) {
            if(str[j] == 'X') {
                x[cnt] = i;
                y[cnt++] = j;
                maze[i][j] = 1;
            }
        }
    }
    for(int d = 1; d < n; d++) {
        int ok = 1;
        for(int i = 0; i < cnt; i++) {
            if(maze[x[i]][y[i] + d]) {
                ok = 0;
                break;
           }
        }
        if(ok) {
            //cout << d << endl;
            store.push_back(d);
        }
    }
    store.push_back(n);
}


void dfs(int D, int step) {
    if( (9 - step) * store[0] + D >= res) return;
    if(step == 9) {
        res = D;
        return;
    }
    for(int i = 0; i < store.size(); i++) {
        int ok = 1;
        for(int j = 0; j < cnt; j++) {
            if(maze[x[j]][y[j] + store[i] + D]) {
                ok = 0 ;
                break;
            }
        }
        if(ok) {
            for(int j = 0; j < cnt; j++) {
                maze[x[j]][y[j] + store[i] + D] = 1;
            }
            dfs(D + store[i], step + 1);
            for(int j = 0; j < cnt; j++) {
                maze[x[j]][y[j] + store[i] + D] = 0;
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> n && n) {
        init();
        dfs(0, 0);
        cout << res + n << endl;
    }
    return 0;
}