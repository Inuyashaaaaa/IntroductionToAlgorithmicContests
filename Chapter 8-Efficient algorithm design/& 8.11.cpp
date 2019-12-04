#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

struct Node {
    double x, h;
    double l, r;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.r < n2.r;
    }
}node[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, D;
    while(cin >> L >> D) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> node[i].x >> node[i].h;
            double w = sqrt(D * D - node[i].h * node[i].h);
            node[i].l = node[i].x - w;
            node[i].r = node[i].x + w;
        }
        sort(node, node + n);
        int cnt = 1;
        double w = node[0].r;
        for(int i = 1; i < n; i++) {
            if(node[i].l <= w) continue;
            w = node[i].r;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}