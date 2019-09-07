#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 200 + 10;

int cap[3];
bool vis[maxn][maxn];
int ans[maxn];

struct Node {
    int v[3];
    int dist;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.dist > n2.dist;
    }
};

void updateAns(const Node& n) {
    for(int i = 0; i < 3; i++) {
        int v = n.v[i];
        if(ans[v] < 0 || n.dist < ans[v]) ans[v] = n.dist; 
    }
}

void solve(int a, int b, int c, int d) {
    memset(ans, -1, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    ans[0] = 0;
    cap[0] = a; cap[1] = b; cap[2] = c;
    Node begin;
    begin.dist = 0;
    begin.v[0] = 0; begin.v[1] = 0;
    begin.v[2] = c;
    priority_queue<Node> pq;
    pq.push(begin);
    vis[0][0] = true;
    while(!pq.empty()) {
        Node n = pq.top();
        pq.pop();
        updateAns(n);
        if(ans[d] >= 0) break;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    if(n.v[i] == 0 || n.v[j] == cap[j]) continue;
                    int amount = min(n.v[i], cap[j] - n.v[j]);
                    Node n1 = n;
                    n1.v[i] -= amount;
                    n1.v[j] += amount;
                    n1.dist += amount;
                    if(!vis[n1.v[0]][n1.v[1]]) {
                        pq.push(n1);
                        vis[n1.v[0]][n1.v[1]] = 1;
                    }
                }
            }
        }
    }
    while(d >= 0) {
        if(ans[d] >= 0) {
            cout << ans[d] << " " << d << endl;
            return;
        }
        d--;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }    
    return 0;
}