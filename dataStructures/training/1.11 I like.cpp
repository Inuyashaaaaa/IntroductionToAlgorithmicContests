#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e5 + 10;

string s[maxn];
int cnt[maxn];
int name[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        name[i] = i;
    }
    cin >> m;
    int a, b;
    ms(cnt);
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        name[a] = name[b];
        cnt[a] = 1;
        cnt[a] += cnt[b];
    }
    for(int i = 1; i <= cnt[1]; i++) {
        cout << "I_love_";
    }
    cout << s[name[1]] << endl;
    return 0;
}