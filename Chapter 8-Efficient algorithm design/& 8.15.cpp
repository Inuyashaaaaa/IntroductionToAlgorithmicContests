#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

struct Node {
    int l, r;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.r < n2.r || n1.r == n2.r && n1.l < n2.l;
    }
}node[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> node[i].l >> node[i].r;
        }
        sort(node, node + n);
        int cur = node[0].r;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(cur == node[i].r) continue;
            if(node[i].l > cur) {
                cur = node[i].r;
                cnt++;
            } else {
                cur++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}