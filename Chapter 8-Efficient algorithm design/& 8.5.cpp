#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 10; // 2^13 = 8192 will be enough
int a[14][maxn]; // (1 - 13) dir 
char pic[maxn][maxn];

// 0 -> right  
// 3 -> left 
// 1 -> top
// 2 -> bot
int getRev(int i) {
    return 3 - i; 
}

char change(int i) {
    if(i == 0) return 'r';
    if(i == 1) return 't';
    if(i == 2) return 'b';
    if(i == 3) return 'l';
}

//[l, r]
void dfs(int l, int r, int n) {
    if(r == l + 1) {
        a[n][l] = 0;
        a[n][r] = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    dfs(l, mid, n);
    int m = (mid + 1 + r) / 2;
    for(int i = mid + 1; i <= m; i++) {
        a[n][i] = getRev(a[n][i - mid]);
    }
    for(int i = m + 1; i <= r; i++) {
        a[n][i] = a[n][i - mid];
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        // 0 -> right  
        // 3 -> left 
        // 1 -> top
        // 2 -> bot
        dfs(1, pow(2, n), n);
        bool dir[4]; 
        ms(dir);
        dir[a[n][1]] = true;
        int dxR = 0;
        int dxL = 0;
        int dyT = 0;
        int dyB = 0;
        int x = 0;
        int y = 0;
        for(int i = 2; i <= pow(2, n); i++) {
            if(a[n][i] == 0) {
                if(dir[1]) x--;
                y++;
            }
            if(a[n][i] == 1) {
                if(dir[1]) x--;
                else if(dir[0]) y++;
                else if(dir[3]) y--;
            }
            if(a[n][i] == 2) {
                x++;
                if(dir[0]) y++;
                else if(dir[3]) y--;
            }
            if(a[n][i] == 3) {
                if(dir[1]) x--;
                y--;
            }
            //cout << "x: " << x << " y: " << y <<endl;
            ms(dir);
            dir[a[n][i]] = true;
            dxR = max(x, dxR);
            dxL = min(x, dxL);
            dyT = max(y, dyT);
            dyB = min(y, dyB);
        }
        ms(pic);
        x = abs(dxL);
        y = abs(dyB);
        //cout << x << " " << y << endl;
        pic[x][y] = a[n][1] == 0 || a[n][1] == 3 ? '_' : '|';
        ms(dir);
        dir[a[n][1]] = true;
        for(int i = 2; i <= pow(2, n); i++) {
            if(a[n][i] == 0) {
                if(dir[1]) x--;
                y++;
            }
            if(a[n][i] == 1) {
                if(dir[1]) x--;
                else if(dir[0]) y++;
                else if(dir[3]) y--;
            }
            if(a[n][i] == 2) {
                x++;
                if(dir[0]) y++;
                else if(dir[3]) y--;
            }
            if(a[n][i] == 3) {
                if(dir[1]) x--;
                y--;
            }
            ms(dir);
            dir[a[n][i]] = true;
            pic[x][y] = a[n][i] == 0 || a[n][i] == 3 ? '_' : '|';
            //cout << "x :" << x << " y : " << y;
            //cout << pic[x][y] << " " << endl;
        }
        //cout << endl;
        int len[maxn];
        ms(len);
        for(int i = 0; i <= abs(dxL) + abs(dxR); i++) {
            for(int j = 0; j <= abs(dyB) + abs(dyT); j++) {
                if(pic[i][j]) len[i] = j;
            }
        }
        for(int i = 0; i <= abs(dxL) + abs(dxR); i++) {
            for(int j = 0; j <= len[i]; j++) {
                if(pic[i][j]) cout << pic[i][j];
                else cout << " ";
            }
            cout << endl;
        }
        cout << "^" << endl;
    }
    return 0;
}