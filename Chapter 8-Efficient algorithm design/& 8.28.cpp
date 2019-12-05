#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int LMAX = 1e6 + 10;
const int PMAX = 5e3 + 10;

int _left[LMAX];
int _right[LMAX];
int level[LMAX];
int opos[LMAX];
bool vis[LMAX];

void del(int i) {
    vis[i] = true;
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
    for(int i = 1; i <= T; i++) {
        ms(vis);
        ms(level);
        int l, p;
        cin >> l >> p;
        for(int j = 0; j < l; j++) {
            _left[j] = j - 1;
            _right[j] = j + 1;
        }
        _left[0] = l - 1;
        _right[l - 1] = 0;
        int _top, _bot;
        for(int j = 0; j < p; j++) {
            cin >> _top >> _bot;
            level[_top] = 1;
            level[_bot] = -1;
            opos[_top] = _bot;
            opos[_bot] = _top;
        }
        for(int j = 0; j < l; j++) {
            if(!level[j]) del(j);
        }
        int num = 2 * p;
        int k = 0;
        while(num) {
            bool ok = true;
            while(vis[k]) k++;
            for(int j = _right[k]; ok && j != k; j = _right[j]) {
                //passing
                int w1 = j;
                int w2 = _right[j];
                if(level[w1] == level[w2] && (
                    _right[opos[w1]] == opos[w2] ||
                    _right[opos[w2]] == opos[w1]
                )) {
                    ok = 0;
                    num -= 4;
                    del(w1); del(w2);
                    del(opos[w1]);
                    del(opos[w2]);
                } else {
                    if(opos[w1] == w2) {
                        ok = 0;
                        num -= 2;
                        del(w1); del(w2);
                    }
                }
            }
            if(ok) break;
        }
        cout << "Case #" << i << ": ";
        cout << (num ? "NO" : "YES") << endl;
    }
    return 0;
}