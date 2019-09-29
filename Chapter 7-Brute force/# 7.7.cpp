#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e3 + 10;

unordered_set<LL> s;
LL arr[maxn];
LL ans[maxn];

bool better(LL d) {
    for(LL i = d; i >= 0; i--) {
        if(arr[i] != ans[i]) {
            return ans[i] == -1 || arr[i] < ans[i];
        }
    }
    return false;
}

bool dfs(LL d, LL maxd, LL a, LL b, LL maxe) {
    if(d == maxd) {
        if(a == 1 && !s.count(b)) {
            arr[d] = b;
            if(better(d)) {
                for(LL i = 0; i <= d; i++) {
                    ans[i] = arr[i];
                }
            }
            return true;
        }
        return false;
    }
    LL fir = max(b / a + 1, maxe);
    bool ok = false;
    for(LL i = fir;; i++) {
        if(s.count(i)) continue;
        // IDA* 启发函数
        if((maxd - d + 1) * b  <= i * a) break;
        LL t = i * b;
        LL left = a * i - b;
        LL g = __gcd(t, left);
        arr[d] = i;
        if (dfs(d + 1, maxd, left / g, t / g, i + 1)) ok = true;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        cout << "Case " << ++kase << ": ";
        s.clear();
        LL a, b, n;
        cin >> a >> b >> n;
        while(n--) {
            LL x;
            cin >> x;
            s.insert(x);
        }
        LL maxd = 1;
        cout << a << "/" << b << "=";
        for(maxd;;maxd++) {
            //cout << endl << maxd;
            memset(ans, -1, sizeof(ans));
            if(dfs(0, maxd, a, b, b / a + 1))
            break;
        }
        for(LL i = 0; i <= maxd; i++) {
            if(i) cout << "+";
            cout << "1/" << ans[i];
        }
        cout << endl;
    }
    return 0;
}