#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int D, I;
        cin >> D >> I;
        int K = 1;
        for(int i = 0; i < D - 1; i ++) {
            if( I % 2 == 0) {
                K = K * 2 + 1;
                I /= 2;
            } else {
                K = K * 2;
                I = (I + 1) / 2;
            }
        }
        cout << K << endl;
    }
    cin >> T;
    return 0;
}