#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n;
bool vis[3][50];
void search(int cur, int* A) {
    if(cur == n) {
        for(int i = 0; i < n; i++) {
            cout << "(" << i + 1 << "," <<
            A[i] << ")";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[0][i] && !vis[1][cur + i]
        && !vis[2][cur - i + n]) {
            A[cur] = i;
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
            search(cur + 1, A);
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis, 0, sizeof(vis));
    int A[10];
    n = 8;
    search(0, A);

    return 0;
}