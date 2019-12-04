#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e6 + 10;
int rain[maxn];
int pre[maxn];
int ans[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        set<int> s;
        int n, m;
        cin >> n >> m;
        ms(pre), ms(ans);
        bool flag = true;
        REP(i, 0, m) cin >> rain[i];
        REP(i, 0, m) {
            if(rain[i] == 0) {
                s.insert(i);
                continue;
            }
            ans[i] = -1; //表示这一天不需要喝水
            auto it = s.lower_bound(pre[rain[i]]);
            if(it == s.end()) {
                flag = false;
                break;
            }
            pre[rain[i]] = i;
            ans[*it] = rain[i];
            s.erase(it);
        }
        if(!flag) {
            cout << "NO" << endl;
            continue;
        }
        bool first = true;
        cout << "YES" << endl;
        REP(i, 0, m) {
            if(ans[i] == -1) continue;
            if(first) cout << ans[i];
            else cout << " " << ans[i];
            first = false;
        }
        cout << endl;
    }
    return 0;
}