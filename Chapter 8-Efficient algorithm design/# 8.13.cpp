#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
int p[maxn]; // 加油
int q[maxn]; // 


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    //Case 1: N
    while(T--) {
        cout << "Case " << ++kase << ": ";
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> q[i];
        LL sum = 0;
        int i;
        bool flag2 = false;
        for(i = 0; i < n; i++) {
            bool flag = true;
            sum = 0;
            for(int j = i; j < i + n; j++) {
                int e = j % n;
                sum += p[e];
                sum -= q[e];
                if(sum < 0) {
                    flag = false;
                    if(i != j)
                    i = j;
                    break;
                }
            }
            if(flag) {
                flag2 = true;
                break;
            }
        }
        if(flag2) cout << "Possible from station " << i + 1 << endl;
        else cout << "Not possible" << endl;
    }
    return 0;
}