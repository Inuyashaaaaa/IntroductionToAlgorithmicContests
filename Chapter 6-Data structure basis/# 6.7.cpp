#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 20;

struct petri {
    int in[maxn];       //起点
    int out[maxn];      //终点
    int iCnt;
    int oCnt;
    int i[maxn];
    int o[maxn];
}p[maxn];

int token[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    int n;
    int kase = 0;
    while(cin >> n && n) {
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= n; i++)
            cin >> token[i];
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++) {
            int x;
            while(cin >> x && x) {
                if(x < 0)
                p[i].in[-x]++;
                else
                p[i].out[x]++;
            }
            for(int j = 1; j <= n; j++) {
                if(p[i].in[j])
                p[i].i[++p[i].iCnt] = j;
                if(p[i].out[j])
                p[i].o[++p[i].oCnt] = j;
            }
        }
        int trans;
        cin >> trans;
        int cnt = 0;
        for(int i = 1; i <= q; i++) {
            bool flag = true;
            for(int j = 1; j <= p[i].iCnt; j++) {
                if(p[i].in[p[i].i[j]] > token[p[i].i[j]]) {
                    flag = false;
                    continue;
                }
            }
            if(!flag)
            continue;
            for(int j = 1; j <= p[i].iCnt; j++) {
                token[p[i].i[j]] -= p[i].in[p[i].i[j]];
            }
            for(int j = 1; j <= p[i].oCnt; j++) {
                token[p[i].o[j]] += p[i].out[p[i].o[j]];
            }
            i = 0;
            if(++cnt >= trans) break;
        }
        if(cnt >= trans) cout << "Case " << ++ kase << 
        ": still live after " << trans << " transitions\n";
        else cout << "Case " << ++ kase << 
        ": dead after " << cnt << " transitions\n";
        cout << "Places with tokens:";
        for(int i = 1; i <= n; ++i) if(token[i]) cout << " " << i <<
        " (" << token[i] << ")";
        cout << endl << endl;
    }
}