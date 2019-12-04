#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    int maxn = 1e2;
    for(int i = 0; i < maxn; i++)
    {
        int w = rand() % int(1e5);
        cout << w << endl;
        for(int j = 0; j < w; j++) {
            cout << rand() % w + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}