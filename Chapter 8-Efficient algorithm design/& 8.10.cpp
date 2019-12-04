#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

struct Node {
    int id, v;
    bool sym;
}node[maxn];

bool cmp1(const Node& n1, const Node& n2) {
    return n1.v > n2.v;
}

bool cmp2(const Node& n1, const Node& n2) {
    return n1.id < n2.id;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> node[i].v;
            node[i].id = i;
        }
        sort(node, node + n, cmp1);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            if(tot <= 0) {
                tot += node[i].v;
                node[i].sym = 0;
            } else {
                tot -= node[i].v;
                node[i].sym = 1;
            }
        }
        if(tot == 0) {
            sort(node, node + n, cmp2);
            cout << "Yes" << endl;
            for(int i = 0; i < n; i++) {
                if(i) cout << " ";
                cout << (node[i].sym == 0 ? 1 : -1);
            }
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}