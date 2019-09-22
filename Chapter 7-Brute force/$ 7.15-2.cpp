#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxs = 60;  // 25 + 16 + 9 + 4 + 1 = 55;
const int maxm = 60;  // 2 * 5 * (5 + 1) = 60;
int n, m;
int best;
int exist[maxm];
int size[maxs];
int fullSize[maxs];
int contain[maxs][maxm];

inline int matchCount() {
    return 2 * n * (n + 1);
}

inline int SquareCount() {
    int ret = 1;
    for(int i = 2; i <= n; i++) {
        ret += i * i;
    }
    return ret;
}

inline int rowMatch(int x, int y) {
    return (2 * n + 1) * x + y;
}

inline int colMatch(int x, int y) {
    return (2 * n + 1) * x + y + n;
}

void init() {
    cin >> n >> m;
    for(int i = 0; i < matchCount(); i++) exist[i] = 1;
    while(m--) {
        int a;
        cin >> a;
        exist[a - 1] = 0;
    }    
    //长度为1开始
    int cnt = 0;
    memset(contain, 0, sizeof(contain));
    for(int i = 1; i <= n; i++) {
        for(int x = 0; x <= n - i; x++) {
            for(int y = 0; y <= n - i; y++) {
                //大小
                size[cnt] = 0;
                fullSize[cnt] = 4 * i;
                for(int p = 0; p < i; p++) {
                    int _top = rowMatch(x    , y + p);
                    int _bot = rowMatch(x + i, y + p);
                    int _lef = colMatch(x + p, y    );
                    int _rig = colMatch(x + p, y + i);
                    contain[cnt][_top] = 1;
                    contain[cnt][_bot] = 1;
                    contain[cnt][_lef] = 1;
                    contain[cnt][_rig] = 1;
                    size[cnt] += exist[_top] + exist[_bot] + exist[_lef] + exist[_rig];
                }
                ++cnt;
            }
        }
    }
}

int findSquare() {
    for(int i = 0; i < SquareCount(); i++) {
        if(fullSize[i] == size[i]) return i;
    }
    return -1;
}

void dfs(int d) {
    if(d >= best) return;
    int s = findSquare();
    if(s == -1) {
        best = d;
        return;
    }
    for(int i = 0; i < matchCount(); i++) {
        if(contain[s][i]) {
            for(int j = 0; j < SquareCount(); j++) {
                if(contain[j][i]) size[j]--;
            }
            dfs(d + 1);
            for(int j = 0; j < SquareCount(); j++) {
                if(contain[j][i]) size[j]++;
            }
        }
    }
}

int solve() {
    init();
    best = n * n;
    dfs(0);
    return best;
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << endl;
    }
    return 0;
}