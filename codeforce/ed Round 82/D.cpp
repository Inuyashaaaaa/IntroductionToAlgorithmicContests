#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 1e5 + 10;
LL arr[maxn];
LL num[64];
LL need[64];
LL value[64];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        LL a, n;
        ms(num);
        ms(need);
        cin >> a >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            for(int j = 0; j < 64; j++) {
                if(((arr[i] >> j) & 1) == 1) {
                    num[j]++;
                }
            }
        }
        for(int i = 0; i < 64; i++) {
            if((a >> i) & 1) {
                need[i]++;
            }
        }
        bool flag = true;
        LL ans = 0;
        for(int i = 0; i < 64; i++) {
            if(need[i]) {
                if(num[i]) {
                    num[i] -= 1;
                    continue;
                }
                else {
                    // 向下找
                    bool flag1 = false;
                    LL val = 1;
                    LL temp[64];
                    for(int j = i - 1; j >= 0; j--) {
                        temp[j] = num[j];
                    }
                    for(int j = i - 1; j >= 0; j--) {
                        val *= 2;
                        LL d = min(val, temp[j]);
                        val -= d;
                        temp[j] -= d;
                        if(val == 0) {
                            flag1 = true;
                            break;
                        }
                    }
                    if(flag1) {
                        for(int j = i - 1; j >= 0; j--) {
                            num[j] = temp[j];
                        }   
                    }
                    if(!flag1) {
                        // 向上找
                        for(int j = i + 1; j < 64; j++) {
                            if(num[j]) {
                                ans += j - i;
                                num[j]--;
                                flag1 = true;
                                for(int k = j - 1; k >= i; k--) {
                                    num[k]++;
                                }
                                break;
                            }
                        }
                    }
                    if(!flag1) {
                        goto END;
                    }
                }
            }
        }
        cout << ans << endl;
        continue;
        END:
            cout << -1 << endl;
    }
    return 0;
}