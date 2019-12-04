#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;

struct Node {
    int city; //当前城市
    int c, t; //费用,时间
    Node(int c = 1000, int t = 0):c(c), t(t){}
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.c == n2.c ? n1.t > n2.t : n1.c > n2.c;
    }
};

vector<int> G[maxn];
bool selected[maxn];
Node D[maxn][maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ms(selected);
    int N, M; //N个城市 M个线路
    cin >> N >> M;
    int a, b, c, t;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c >> t;
        if(D[a][b].c == 1000) { 
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(c < D[a][b].c || (c == D[a][b].c && t < D[a][b].t)) {
            D[a][b].c = c;
            D[a][b].t = t;
        }
    }

    priority_queue<Node> pq;
    Node n;
    n.city = 1;
    n.c = 0;
    n.t = 0;
    pq.push(n);
    bool flag = false;
    while(!pq.empty()) {
        n = pq.top();
        pq.pop();
        int city = n.city;
        if(city == N) {
            flag = true;
            break;
        }
        selected[city] = true;
        int sz = G[city].size();
        for(int i = 0; i < sz; i++) {
            int cityNow = G[city][i];
            if(selected[cityNow]) continue;
            Node temp;
            temp.city = cityNow;
            temp.c = n.c + D[city][cityNow].c;
            temp.t = n.t + D[city][cityNow].t;
            pq.push(temp);
        }
    }
    if(flag) {
        cout << n.c << " " << n.t << endl;
    } else {
        cout << -1 << endl;
    }
    
    
    return 0;
}