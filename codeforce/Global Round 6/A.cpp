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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sz = s.size();
        bool haveZero = false;
        int haveEven = 0;
        int aa = 0;
        for(int j = 0; j < sz; j++) {
            if(s[j] == '0') {
                haveZero = true;
            }
            if((s[j] - '0') % 2 == 0) {
                haveEven++;
            }
            aa += (s[j] - '0');
        }
        if(aa % 3 == 0 && haveZero && haveEven >= 2) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
    return 0;
}