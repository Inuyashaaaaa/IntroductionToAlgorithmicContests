#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e5 + 10;
map<int,string> m;

struct Node{
    int name;
    int cnt;
    Node():cnt(0){}
}node[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        m[i] = s;
        node[i].name = i;
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        node[a].name = node[b].name;
        node[a].cnt = node[b].cnt + 1;
    }
    for(int i = 1; i<= node[1].cnt; i++) {
        cout << "I_love_";
    }
    cout << m[node[1].name] << endl;
    return 0;
}