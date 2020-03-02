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
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int firstOne = 0;
        int lastOne = -1;
        int size = s.size();
        for(int i = 0; i < size; i++) {
            if(s[i] == '1') {
                firstOne = i;
                break;
            }
        }
        for(int i = size - 1; i >= 0; i--) {
            if(s[i] == '1') {
                lastOne = i;
                break;
            }
        }
        int cnt = 0;
        for(int i = firstOne; i <= lastOne; i++) {
            if(s[i] == '0') {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}