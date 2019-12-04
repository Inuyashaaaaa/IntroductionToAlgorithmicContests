#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        cout << "Case " << ++kase << ": ";
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;    // 统计 '?'
        int zero1 = 0;  // s1 '0'
        int zero2 = 0;  // s1 '1'
        int len = s1.size();
        for(int i = 0; i < len; i++) {
            if(s1[i] == '?') cnt++;
            if(s1[i] == '0') zero1++;
            if(s2[i] == '0') zero2++;
        }
        if(zero1 + cnt < zero2) {
            cout << -1 << endl;
            continue;
        }
        int left1 = zero2 - zero1;
        int left2 = (len - zero2) - (len - zero1 - cnt);
        int ans = 0;
        for(int i = 0; i < len; i++) {
            if(s1[i] == '?') {
                ans++;
                if(s2[i] == '0') {
                    if(left1) {
                        s1[i] = '0';
                        left1--;
                    } else {
                        s1[i] = '1';
                    }
                }
                else {
                    if(left2) {
                        s1[i] = '1';
                        left2--;
                    } else {
                        s1[i] = '0';
                    }
                }
            }
        }
        for(int i = 0; i < len; i++) {
            if(s1[i] == '0' && s2[i] == '1') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}