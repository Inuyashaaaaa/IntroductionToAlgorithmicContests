#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 10 + 5;

int a[maxn];
int n;
bool isSort() {
    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] != a[i] + 1) return false;
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
    if(d * 3 + h() > maxd * 3) return false; 
    if(isSort()) return true;
    int b[maxn];
    int old[maxn];
    memcpy(old, a, sizeof(a));
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
          
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                if(k < i || k > j) b[cnt++] = old[k];
            }
            for(int k = 0; k <= cnt; k++) {
                int cnt2 = 0;
                for(int p = 0; p < k; p++) a[cnt2++] = b[p];
                for(int p = i; p <= j; p++) a[cnt2++] = old[p];
                for(int p = k; p < cnt; p++) a[cnt2++] = b[p];

                if(dfs(d + 1, maxd)) return true;
                memcpy(a, old, sizeof(a));
            }
        }
    }
    return false;
}

int solve() {
    if(isSort()) return 0;
    int maxn = 5; //刘汝佳告诉我们5是在题设这种情况的最大解
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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Case " << ++kase << ": ";
        cout << solve() << endl;
    }
    return 0;
}