#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 10;
int a[maxn];
int n;

bool isSort() {
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1] - 1) return false;
    }
    return true;
}

int h() {
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i - 1] + 1) cnt++;
    }
    if(a[0] != 1) cnt++;
    return cnt;
}

bool dfs(int d, int maxd) {
    if(3 * d + h() > 3 * maxd) return false;
    if(isSort()) return true;
    int old[maxn], b[maxn];
    memcpy(old, a, sizeof(a));
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            //cut
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                if(k < i || k > j) b[cnt++] = old[k];
            }
            for(int k = 0; k <= cnt; k++) {
                int cnt2 = 0;
                for(int w = 0; w < k; w++) a[cnt2++] = b[w];
                for(int w = i; w <= j; w++) a[cnt2++] = old[w];
                for(int w = k; w < cnt; w++) a[cnt2++] = b[w]; 
                if(dfs(d + 1, maxd)) return true;
                memcpy(a, old, sizeof(a)); //回溯
            }
        }
    }
    return false;
}

int solve() {
    if(isSort()) return 0;
    int maxA = 5; //最大解为5 Rujia Liu 说的
    for(int maxd = 1; maxd < 5; maxd++) {
        if(dfs(0, maxd)) return maxd; 
    }
    return 5;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while(cin >> n && n) {
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        cout << "Case " << ++kase << ": ";
        cout << solve() << endl;
    }    
    return 0;
}