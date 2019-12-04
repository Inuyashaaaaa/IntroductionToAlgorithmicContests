#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 3e5;
bool valid[maxn];
int cnt[maxn];
int pos[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ms(valid);
        ms(cnt);
        ms(pos);
        int s, n;
        cin >> s >> n;
        for(int i = s; i < n + s; i++) cin >> pos[i];
        int tot = 0;
        for(int i = 0; i <= n + s; i++) {
            if(tot == i && i < s) valid[i] = true;
            if(tot == s) valid[i] = true;
            if(tot == n + s - i && i > n) valid[i] = true;
            if(i == n + s) break;
            if(pos[i] != 0 && --cnt[pos[i]] == 0) tot--;
            if(pos[i + s] != 0 && ++cnt[pos[i + s]] == 1) tot++;  
        }  
        LL ans = 0;
        // for(int i = 0; i <= n + s; i++) {
        //     cout << valid[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < s; i++) {
            bool flag = true;
            for(int j = i; j <= n + s; j += s) {
                if(!valid[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        if(ans == n + 1) ans = s;
        cout << ans << endl;
    }

    return 0;
}
