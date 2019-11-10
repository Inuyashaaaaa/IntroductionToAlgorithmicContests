#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define INF 0x7fffffff
using namespace std;
const int maxn = 2e5 + 10;
int arr[maxn];
int g[maxn]; //which means most length end with i
int f[maxn]; //which means most length begin with i

struct Node {
    int a, g; //a means a[i]  g means most length end with i
    Node(int a, int g): a(a), g(g) {}
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.a < n2.a;
    }
};

set<Node> s;


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
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        // g
        g[0] = 0;
        arr[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(arr[i] > arr[i - 1]) {
                g[i] = g[i - 1] + 1;
            } else {
                g[i] = 1;
            }
        }   
        // f
        f[n + 1] = 0;
        arr[n + 1] = INF;
        for(int i = n; i >= 1; i--) {
            if(arr[i] < arr[i + 1]) {
                f[i] = f[i + 1] + 1;
            } else {
                f[i] = 1;
            }
        }
        int ans = -1;
        s.clear();
        s.insert(Node(0, 0));
        for(int i = 1; i <= n; i++) {
            Node n = Node(arr[i], g[i]);
            auto it = s.lower_bound(n);
            bool keep = true;
            if(it != s.begin()) {
                auto last = --it;
                int len = f[i] + last->g;
                ans = max(len, ans);
                if(n.g <= last->g) keep = false;
            }
            if(keep) {
                s.erase(n);
                s.insert(n);
                it = s.find(n);
                it++;
                while(it != s.end() && it->g <= n.g) s.erase(it++);
            }
        }
        cout << ans << endl;
        //
    }
    return 0;
}