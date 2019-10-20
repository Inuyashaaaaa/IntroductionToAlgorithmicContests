#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 10;

int n;
char pic[maxn][maxn];
int c[maxn][maxn], d[maxn][maxn];
int pa[maxn * maxn + 1];

int find(int p) {
    return p == pa[p] ? p : find(pa[p]);
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << pic[i][j];
        }
        cout << endl;
    }
}

bool dfs(int x, int y) {
    if(n == x) {
        for(int i = 0; i <= n; i++) {
            if(c[n][i] != -1 && c[n][i] != d[n][i]) return 0;
        }
        print();
        return 1;
    }
    if(n == y) {
        if(c[x][n] != -1 && c[x][n] != d[x][n]) return 0;
        return dfs(x + 1, 0);
    }
    int p = x * (n + 1) + y;
    int q = p + n + 1;
    if(c[x][y] < 0 || c[x][y] == d[x][y] + 1) {
        int p1 = find(p);
        int q1 = find(q + 1);
        pic[x][y] = '\\';  d[x][y]++;  d[x + 1][y + 1]++;  pa[p1] = q1; 
        if(dfs(x, y + 1)) return true;
        d[x][y]--;  d[x + 1][y + 1]--;  pa[p1] = p1;
    }
    if((c[x][y] < 0 || c[x][y] == d[x][y]) && find(p + 1) != find(q)) {
        int p1 = find(q);
        int q1 = find(p + 1);
        pic[x][y] = '/';  d[x][y + 1]++;  d[x + 1][y]++;  pa[p1] = q1;
        if(dfs(x, y + 1)) return true;
        d[x][y + 1]--;  d[x + 1][y]--;  pa[p1] = p1;
    } 
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                cin >> pic[i][j];
                if(pic[i][j] == '.') c[i][j] = -1;
                else c[i][j] = pic[i][j] - '0';
            }
        }
        for(int i = 0; i <= (n + 1) * (n + 1); i++) {
            pa[i] = i;
        } 
        ms(d);
        dfs(0, 0);
    }
    return 0;
}