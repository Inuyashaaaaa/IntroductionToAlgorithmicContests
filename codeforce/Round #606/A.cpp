#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

LL b[10];

int count(int a) {
    int ret = 0;
    while(a) {
        ret++;
        a /= 10;
    }   
    return ret;
}

void change(int num) {
    ms(b);
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < num; j++) {
            b[i - 1] *= 10;
            b[i - 1] += i;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int a;
        cin >> a;
        int c = count(a);
        //cout << c << endl;
        change(c);
        int ans = (c - 1) * 9;
        for(int i = 0; i < 9; i++) {
            if(a >= b[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}