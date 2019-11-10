#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e2 + 10;

map<string, int> m1;
map<int, int> m2;
map<int, string> m3;
vector<int> G[maxn];
int maxd = 0;

void dfs(int u, int d) {
    bool isEnd = true;
    for(auto& num: G[u]) {
        dfs(num, d + 1);
        isEnd = false;
    }
    if(isEnd) 
        if(d > maxd)
            maxd = d;
}

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
        int id = 0;

        m1.clear();
        m2.clear();
        m3.clear();
        for(int i = 0; i < maxn; i++) {
            G[i].clear();
        }

        string s1, s2;
        for(int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if(!m1.count(s1)) {
                m1[s1] = ++id;
                m3[id] = s1;
            }
            if(!m1.count(s2)) {
                m1[s2] = ++id;
                m3[id] = s2;
            }
            G[m1[s1]].push_back(m1[s2]);
        }
        map<int, string, greater<int>> m;
        for(int i = 1; i <= id; i++) {       
            maxd = 0;
            dfs(i, 0);
            //cout << m3[i] << " " << maxd << endl;
            m[maxd] = m3[i];
        }
        bool first = true;
        for(auto& pair: m) {
            if(!first) cout << " ";
            cout << pair.second;
            first = false;
        }
        cout << endl;
    }
    return 0;
}