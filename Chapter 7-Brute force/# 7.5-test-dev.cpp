#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int maxn = 100000;
    srand(time(NULL));
    for(int i = 0; i < maxn; i++) {
        int w;
        w = rand() % 19 + 1;
        cout << w << endl;
        for(int j = 1; j <= 5; j++) {
            for(int k = 0; k < w; k++) {
                cout << (rand() % 4 == 0 ? '.' : 'X');
            }
            cout << endl;
        }
    }
    cout << 0 << endl;
    return 0;
}