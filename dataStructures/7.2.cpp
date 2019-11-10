#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e3 + 10;

map<int, vector<pair<int, int>>> m1;
bool vis[maxn][maxn];


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ms(vis);

    //实际
    for(int i = -1000; i <= 1000; i++) {
        for(int j = -1000; j <= 1000; j++) {
            double l = sqrt(i * i + j * j);
            int l1 = int(l);
            if(fabs(l - l1) < 1e-6) {
                m1[l1].push_back(make_pair(i, j));
            }
        }
    }

    int T;
    int a, b;
    LL ai = 0, bi = 0;
    int size = 0;
    cin >> T;
    string command;
    while(T--) {
        cin >> command;
        if(command[0] == 'i') {
            cin >> a >> b;
            if(vis[a + 1000][b + 1000]) continue;
            vis[a + 1000][b + 1000] = true;
            ai += a;
            bi += b;
            size++;
            cout << "size = " << size << endl;
        } else if (command[0] == 'd') {
            cin >> a >> b;
            if(!vis[a + 1000][b + 1000]) continue;
            vis[a + 1000][b + 1000] = false;
            ai -= a;
            bi -= b;
            size--;
            cout << "size = " << size << endl;
        } else if (command[0] == 'p') {
            cin >> a;
            if(m1.count(a)) {
                int sz = m1[a].size();
                for(int i = 0; i < sz; i++) {
                    int c = m1[a][i].first;
                    int d = m1[a][i].second;
                    if(!vis[c + 1000][d + 1000]) continue;
                    vis[c + 1000][d + 1000] = false;
                    ai -= c;
                    bi -= d;
                    size--;
                }
            }
            cout << "size = " << size << endl;
        } else if (command[0] == 'v') {
            cout << "value = " << ai * ai + bi * bi << endl;
        }
        
    }

    return 0;
}