#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
int G[maxn][maxn];
int n;

void euler(int u) {
    for(int v = 1; v <= n; v++) {
        if(G[u][v]){
            G[u][v] = G[v][u] = 0; 
            euler(v);
            printf("%d %d\n", u, v);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    euler(3);
}