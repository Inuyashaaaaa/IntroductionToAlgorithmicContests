#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;

struct Node {
    int p, d;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.d < n2.d;
    }
}node[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        if(kase++) std::cout << endl;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> node[i].p >> node[i].d;
        }
        sort(node, node + n);
        priority_queue<int> pq;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(node[i].p + cur <= node[i].d) {
                cur += node[i].p;
                pq.push(node[i].p);
            } else {
                if(pq.empty()) continue;
                int v = pq.top();
                if(v >= node[i].p) {
                    pq.pop();
                    cur -= v - node[i].p;
                    pq.push(node[i].p); 
                }
            }
        }
        std::cout << pq.size() << endl;
    }
    return 0;
}