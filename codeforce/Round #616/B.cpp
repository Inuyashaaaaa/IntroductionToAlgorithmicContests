#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            // cout << a[i] << " ";
        }
        // cout << endl;
        bool flag1 = true;
        bool turn = false;
        int index;
        // 0 1 2 3 4 3 2 1 0
        for(int i = 0; i < n; i++) {
            if(!turn) {
                if(a[i] >= i) {
                    // cout << i << " ";
                    continue;
                }
                turn = true;
                i--;
                index = i; // 4
            }
            else {
                index = min(a[i], index - 1);
                if(index >= 0) {
                    continue;
                }
                flag1 = false;
                break;
            } 

        }
        turn = false;
        bool flag2 = true;
        reverse(a, a + n);
        for(int i = 0; i < n; i++) {
            if(!turn) {
                if(a[i] >= i) {
                    continue;
                }
                turn = true;
                i--;
                index = i; // 4
            }
            else {
                index = min(a[i], index - 1);
                if(index >= 0) {
                    continue;
                }
                flag2 = false;
                break;
            } 

        }
        cout << ((flag1 || flag2) ? "Yes" : "No") << endl;


    }
    return 0;
}