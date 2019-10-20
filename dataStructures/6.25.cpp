#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e4 + 10;
int parent[maxn];
struct Node {
    int left, right;
    Node(int left, int right):left(left), right(right){}
    Node(){}
}node[maxn];
int maxd;

int findRoot(int leaf) {
    if(parent[leaf] == -1) return leaf;
    return findRoot(parent[leaf]);
}

void dfs(int d, int root) {
    if(root == -1) {
        if(d > maxd) {
            maxd = d;
        }
        return;
    }
    dfs(d + 1, node[root].left);
    dfs(d + 1, node[root].right);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool flag = true;
    maxd = -1;
    int leaf;
    memset(parent, -1, sizeof(parent));
    for(int i = 0; i < n; i++) {
        int l, o, r;
        cin >> l >> o >> r;
        if((l < o || l == -1) && (o < r || r == -1)) {
            if(l != -1)
            parent[l] = o;
            if(r != -1)
            parent[r] = o;
            node[o].left = l;
            node[o].right = r;
            if(l == -1 && r == -1) {
                leaf = o;
            }
        } else {
            flag = false;
            break;
        }
    }
    if(!flag) {
        cout << "-1" << endl;
        return 0;
    }
    int root = findRoot(leaf);
    dfs(0, root);
    cout << maxd << endl;
    return 0;
}