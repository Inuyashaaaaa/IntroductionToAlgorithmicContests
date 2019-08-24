#include<bits/stdc++.h>
using namespace std;

//分别代表 A- B- C- D- E- F- G- ………… A+ B+ C+
int G[52][52];
int vis[52];

bool dfs(int i) {
    vis[i] = -1; //正在访问
    for(int j = 0; j < 52; j++) {
        if(G[i][j]) {
            if(vis[j] == -1) {
                //cout << i << "*" << j << endl; 
                return false;
            }//环
            if(!vis[j] && !dfs(j)) return false;
        }
    }
    vis[i] = 1;
    return true;
}

bool topSort() {
    for(int i = 0; i < 52;i ++) {
        if(!vis[i]) {
            if(!dfs(i))
                return false;
        }
    }
    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        string s;
        string temp[4];
        memset(vis, false, sizeof(vis));
        memset(G, 0, sizeof(G));
        //构造有向边
        for(int i = 0; i < n; i++) {
            cin >> s;
            temp[0] = s.substr(0, 2);
            temp[1] = s.substr(2, 2);
            temp[2] = s.substr(4, 2);
            temp[3] = s.substr(6, 2);
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    if(j == k) continue;
                    if(temp[j] == "00" || temp[k] == "00") continue;
                    int index1 = temp[j][0] - 'A' + (temp[j][1] == '-' ? 0 : 26);
                    int index2 = temp[k][0] - 'A' + (temp[k][1] == '+' ? 0 : 26);
                    G[index1][index2] = 1;
                    //cout << index1 << " " << index2 << endl;
                }
            }
        }
        if(!topSort()) {
            cout << "unbounded" << endl;
        }
        else {
            cout << "bounded" << endl;
        }
    }
}