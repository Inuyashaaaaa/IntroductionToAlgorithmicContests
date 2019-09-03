#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;

unordered_map<int, vector<int>> m;
int weight[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    memset(weight, 0, sizeof(weight));
    for(int i = 0; i < n; i++) {
        int a, b, c;
        weight[c] += m[a].size();
        weight[c] += m[b].size();
        m[a].push_back(b);
        m[b].push_back(c);
    }    
    return 0;
}    