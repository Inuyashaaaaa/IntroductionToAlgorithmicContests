#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    for(int i = 0; i < 1000; i++) {
        int w = rand() % 32 + 1;
        for(int i = 0; i < w; i++) {
            cout << rand() % 2 == 0 ? '0' : '1';
        }
        cout << endl;
    }
    return 0;
}