#include<bits/stdc++.h>
using namespace std;

bool solve(int& m) {
    int W1, D1, W2, D2;
    cin >> W1 >> D1 >> W2 >> D2;
    bool left = true, right = true;
    if(!W1) left = solve(W1);       //看看左边是否平衡以及获得左边的质量
    if(!W2) right = solve(W2);      //看看右边是否平衡以及获得右边的质量
    m = W1 + W2;
    return left && right && (W1 * D1 == W2 * D2);   //如果任一边不平衡或者这个天平本身不平衡，就是假
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, m;
    cin >> T;
    while(T--) {
        if(solve(m)) cout << "YES" << endl;
        else cout << "NO" << endl;
        if(T)
        cout << endl;
    }
}