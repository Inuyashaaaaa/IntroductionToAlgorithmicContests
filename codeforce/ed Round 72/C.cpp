#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int space[maxn];
        int cnt = 0;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] == '0') {
                space[i] = cnt;
                cnt++;
            } else {
                space[i] = cnt;
                cnt = 0;
            }
        }
        int ans = 0;
        for(int i = len - 1; i >= 0; i--) {
            int num = 0;
            int k = 1;
            for(int j = 0; j < 18 && i - j >= 0; j++) {
                num += (s[i - j] - '0') * k;
                k*= 2;
                if(space[i - j] + j  + 1 >= num && num && s[i - j] == '1') {
                    // cout << "num: " << num << endl;
                    // cout << space[i - j] << endl;
                    // cout << i << " " << j << endl;
                    ans ++;
                }
            }
        }
        cout << ans << endl;
       // cout << endl;

    }
    return 0;
}