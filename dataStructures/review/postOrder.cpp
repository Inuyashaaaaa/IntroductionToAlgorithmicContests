#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e4 +10;
int _left[maxn];
int _right[maxn];

void postOrder(int root) {
    if(_left[root])
    postOrder(_left[root]);
    if(_right[root])
    postOrder(_right[root]);
    cout << root << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    _left[6] = 3;
    _right[6] = 9;
    _right[3] = 4;
    _left[9] = 8;
    _right[9] = 12;
    postOrder(6);
    
    
    return 0;
}