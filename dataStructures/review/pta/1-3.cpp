#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e3 + 10;
int parent[maxn];


void init(int n) {
    for(int i = 1; i <= n; i++) parent[i] = i;
}

int find(int p) {
    while(p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void merge(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot == bRoot) return;
    parent[aRoot] = bRoot;
}



int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    init(2 * n);
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if(ch == 'E') {
            merge(a + n, b);
            merge(b + n, a);
        }
        if(ch == 'F') {
            merge(a, b);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i == parent[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}