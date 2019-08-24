#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;

int inDegree[maxn];
int edge[maxn][maxn];   
int n, m;

int main() {
    while(cin >> n >> m && n) {
        memset(inDegree, 0, sizeof(inDegree));
        memset(edge, 0, sizeof(edge));
        int a, b;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            if(edge[a][b])
            continue;
            edge[a][b] = 1;
            inDegree[b] ++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int ret = q.front();
                ans.push_back(ret);
                q.pop();
                for(int j = 1; j <= n; j++) {
                    if(edge[ret][j]) {
                        edge[ret][j] = 0;
                        inDegree[j] --;
                        if(inDegree[j] == 0)
                        q.push(j);
                    }
                }
            }
        }
        bool first = false;
        if(ans.size() == n) {
            for(auto& num: ans) {
                if(first) cout << " ";
                cout << num;
                first = true;
            }
        }
        cout << endl;
    }
}