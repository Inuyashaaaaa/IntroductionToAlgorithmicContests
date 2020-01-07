#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m;
    cin >> n >> m;
    vector<LL> out(n + 1);
    while(m--) {
        LL a, b, c;
        cin >> a >> b >> c;
        out[a] += c;
        out[b] -= c;
    }
    vector<LL> pos;
    vector<LL> neg;
    for(LL i = 1; i <= n; i++) {
        if(out[i] > 0) {
            pos.push_back(i);
        } 
        if(out[i] < 0) {
            neg.push_back(i);
        }
    }
    LL i = 0, j = 0;
    vector<tuple<LL, LL, LL>> ans;
    while(i < pos.size()) {
        LL x = min(out[pos[i]], -out[neg[j]]);
        out[pos[i]] -= x;
        out[neg[j]] += x;
        ans.emplace_back(pos[i], neg[j], x);
        if(out[pos[i]] == 0) {
            i++;
        }
        if(out[neg[j]] == 0) {
            j++;
        }
    }
    cout << ans.size() << endl;
    for(auto p: ans) {
        cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;
    }
    return 0;
}