#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    int maxn = 1e3;
    for(int i = 0; i < maxn; i++) {
        int w = 1e5;
        cout << w << endl;
        for(int j = 0; j < w; j++) {
            cout << 1e5 << " ";
        }
        cout << endl;
    }
    return 0;
}