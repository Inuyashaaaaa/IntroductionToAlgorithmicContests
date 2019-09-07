#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        LL n, s1, v1, s2, v2;
        cin >> n >> s1 >> v1 >> s2 >> v2;
        // s1 大
        if(s1 < s2) {
            swap(s1, s2);
            swap(v1, v2);
        }
        // s1很小
        LL ans = 0;
        if(n / s1 >= 65536) {
            // v2价格的宝物最多拿 s1 - 1个
            if(s2 * v1 >= s1 * v2) {
                for(LL i = 0; i <= s1 - 1; i++) {  
                    ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
                }
            }
            else {
                for(LL i = 0; i <= s2 - 1; i++) {
                    ans = max(ans, v1 * i + (n - i * s1) / s2 * v2);
                }
            }
        } 
        // s1很大 
        else {
            for(int i = 0; i <= n / s1; i++) {
                ans = max(ans, (LL)(i * v1 + (n - i * s1) / s2 * v2));
            }
        }
        //Case #1:
        cout << "Case #" << ++kase << ": ";
        cout << ans << endl;
    }
    return 0;
}