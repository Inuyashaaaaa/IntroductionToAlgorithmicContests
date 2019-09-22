#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5;

unordered_map<int, vector<int>> m;
int inDegree[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[a]++;
        inDegree[b]++;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    queue<int> qq;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 1) {
            qq.push(i);
        }
    }
    while(1) {
        
    }
    
    return 0;
}