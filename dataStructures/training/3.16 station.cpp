#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int maxA[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> s;
    ms(maxA);
    for(int i = n - 2; i >= 0; i--) {
        maxA[i] = max(maxA[i + 1], a[i + 1]);
    }
    for(int i = 0; i < n; i++) {
        //cout << maxA[i] << " ";
    }
    vector<int> ans;
    int maxn = maxA[0];
    for(int i = 0; i < n; i++) {
        if(a[i] != maxn) {
            s.push(a[i]);
        }
        if(a[i] == maxn) {
            ans.push_back(a[i]);
            while(!s.empty() && s.top() >= maxA[i]) {
                ans.push_back(s.top());
                s.pop();
            }
            maxn = maxA[i];
        }
    }
    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        if(i) cout << ' ';
        cout << ans[i];
    }
    return 0;
}