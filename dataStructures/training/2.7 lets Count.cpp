#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e3 + 10;

int _left[maxn], _right[maxn];
int n, m;

void init() {
    for(int i = 1; i <= n; i++) {
        _left[i] = i - 1;
        _right[i] = i + 1;
    }
    _left[1] = n;
    _right[n] = 1;
}

void Del(int i) {
    n--;
    _left[_right[i]] = _left[i];
    _right[_left[i]] = _right[i];
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        init();
        int now = 0;
        int i = 1, j;
        while(n >= 3) {
            now++;
            if(now == m) {
                now = 0;
                Del(_left[i]);
                Del(_right[i]);
            }
            i = _right[i];
        }
        if(n == 2) {
            j = _right[i];
            if(i > j) {
                swap(i, j);
            }
            cout << i << " " << j << endl;
        }
        else {
            cout << i << endl;
        }
    }
    return 0;
}