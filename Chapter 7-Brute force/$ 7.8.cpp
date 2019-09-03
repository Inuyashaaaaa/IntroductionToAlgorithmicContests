#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 200 + 5;
int cup[3];
int vis[maxn][maxn];
int ans[maxn];

struct Node {
    int v[3];
    int dist;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.dist > n2.dist;
    }
};

void upDateAns(const Node& u) {
    for(int i = 0; i < 3; i++) {
        int v = u.v[i];
        if(ans[v] == -1 || u.dist < ans[v]) ans[v] = u.dist;
    }
}

void solve(int a, int b, int c, int d) {
    cup[0] = a; cup[1] = b; cup[2] = c;
    Node start;
    start.dist = 0;
    start.v[0] = 0; start.v[1] = 0; start.v[2] = c;
    priority_queue<Node> pq;
    pq.push(start);
    vis[0][0] = 1;
    while(!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        upDateAns(u);
        if(ans[d] >= 0) break;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    if(u.v[i] == 0 || u.v[j] == cup[j]) continue;
                    int amount = min(u.v[i], cup[j] - u.v[j]);
                    Node u2 = u;
                    u2.dist += amount;  
                    u2.v[i] -= amount;
                    u2.v[j] += amount;
                    if(!vis[u2.v[0]][u2.v[1]]) {
                        vis[u2.v[0]][u2.v[1]] = 1;
                        pq.push(u2);
                    }
                }
            }
        }
    }
    while(d >= 0) {
        if(ans[d] >= 0) {
            cout << ans[d] << " " << d <<endl;
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
        memset(vis, 0, sizeof(vis));
        memset(ans, -1, sizeof(ans));


        int a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
    return 0;
}