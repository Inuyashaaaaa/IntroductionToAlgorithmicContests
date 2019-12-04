#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
int n, m;
char pic[maxn][maxn];
int h[maxn][maxn];
int ans[maxn * maxn];

struct Node {
    int c, h;
    Node(int c, int h):c(c), h(h){}
    Node(){}
};

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ms(h);
        ms(ans);
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> pic[i][j]; 
                if(pic[i][j] == '.')
                h[i][j] = h[i - 1][j] + 1;
                //cout << h[i][j] << " ";
            }
            //cout << endl;
        }
        for(int i = 1; i <= n; i++) {
            stack<Node> s;
            for(int j = 1; j <= m; j++) {
                if(h[i][j] == 0) {
                    while(!s.empty()) s.pop();
                    continue;
                }
                Node n = Node(j, h[i][j]);
                while(!s.empty() && s.top().h >= h[i][j]) {
                    n.c = s.top().c;
                    s.pop();
                }
                if(s.empty()) {
                    s.push(n);
                } else {
                    if(s.top().h - s.top().c < n.h - n.c) {
                        s.push(n);
                    }
                }
                ans[s.top().h - s.top().c + j + 1]++;
            }
        }
        for(int i = 1; i < maxn * maxn; i++) {
            if(ans[i]) cout << ans[i] << " x " << 2 * i << endl;
        }        
    }
    return 0;
}