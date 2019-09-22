#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 10;
int pic[maxn][maxn];
bool use[30];
int code[maxn][maxn];
int dx[] = {0, 1}; // 上 左 下 右
int dy[] = {1, 0};
int cnt = 0;

void printO() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) {
            cout << setw(4) << pic[i][j];
        }      
        cout << endl; 
    }
    cout << endl;
}

void read() {
    for(int i = 1; i < 8; i++) {
        cin >> pic[0][i];
    }
    for(int i = 1; i < 7; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> pic[i][j];
        }
    }
    printO();
}

void print() {
    cout << endl;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) {
            cout << setw(4) << code[i][j];
        }
        cout << endl;
    }
}

bool check() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) {
            if(code[i][j] == -1) return false;
        }
    }
    return true;
}

int getCode(int x, int y) {
    return 7 * x + y - (x + x * x) / 2 + 1;
}

void dfs(int d, int maxd, int x, int y) {
    if(d == maxd) {
        if(check()) {
            print();
            cnt++;
            cout << endl;
        }
        return;
    }
    if(y == 8) {
        x++; 
        y = 0;
    }
    if(code[x][y] != -1) {
        dfs(d, maxd, x, y + 1);
        return;
    }
    int xx, yy;
    for(int i = 0; i < 2; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if(xx < 0 || xx >= 7 || yy < 0 || yy >= 8) continue;
        if(code[xx][yy] != -1) continue;
        int c1 = pic[x][y];
        int c2 = pic[xx][yy];
        if(c1 > c2) swap(c1, c2);
        int c = getCode(c1, c2);
        if(!use[c]) {
            code[x][y] = code[xx][yy] = c;
            use[c] = true;
            dfs(d + 1, maxd, x, y + 1);
            use[c] = false;
            code[x][y] = code[xx][yy] = -1;
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> pic[0][0]) {
        cnt = 0;
        if(kase)  cout << "\n\n\n\n\n";
        cout << "Layout #" << ++kase << ":\n\n\n";
        read();
        memset(code, -1, sizeof(code));   
        memset(use, 0, sizeof(use)); 
        cout << "Maps resulting from layout #" << kase << " are:\n\n";
        dfs(0, 28, 0, 0);
        cout << "\nThere are "  << cnt << " solution(s) for layout #"  << kase << ".\n";
    }
    return 0;
}