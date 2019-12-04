#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

const int maxn = 3e2 + 10;

int G[maxn][maxn];
int p[maxn];
int sz[maxn];


void init() {
    for(int i = 0; i < maxn; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int q) {
    if(q == p[q]) return q;
    return find(p[q]);
}

void merge(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    p[bRoot] = aRoot;
    sz[aRoot] += sz[bRoot];
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int kase = 0;
    cin >> T;
    while(T--) {
        cout << "Case #" << ++kase << ": ";
        int v, m;
        cin >> v >> m;
        int a, b;
        ms(G);
        init();
        while(m--) {
            cin >> a >> b;
            G[a][b] = 1;
        }
        for(int i = 0; i < v; i++) {
            vector<int> vec;
            for(int j = 0; j < v; j++) {
                if(G[i][j]) vec.push_back(j);
            }
            int size = vec.size();
            if(size)
            for(int j = 0; j < size - 1; j++) {
                merge(vec[j], vec[j + 1]);
            }
        }
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(G[i][j]) {
                    int root = find(j);
                    if(sz[root] != 1) {
                        for(int k = 0; k < v; k++) {
                            if(find(k) == root) {
                                if(!G[i][k]) {
                                    goto END;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Yes" << endl;
        continue;
        END:
        cout << "No" << endl;
    }
    return 0;
}