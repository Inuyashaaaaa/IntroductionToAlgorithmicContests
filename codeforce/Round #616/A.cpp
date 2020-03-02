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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool have_odd = false;
        int have_odd_index;
        int odd_num = 0;
        int even_num = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] % 2 == 1) {
                have_odd = true;
                have_odd_index = i;
                break;
            }
        }
        if(!have_odd) {
            cout << -1 << endl;
            continue;
        }
        for(int i = have_odd_index; i >=0 ;i--) {
            if(s[i] % 2 == 0) {
                even_num ++;
            }
            else {
                odd_num ++;
            }
        }

        if(odd_num % 2 == 1) {
            bool flag = false;
            int index;
            for(int i = have_odd_index - 1; i >= 0; i--) {
                if(s[i] % 2 == 1) {
                    flag = true;
                    index = i;
                    break;
                }
            }
            if(!flag) {
                cout << -1 << endl;
                continue;
            }
            string s1 = s.substr(0, index);
            string s2 = s.substr(index + 1, have_odd_index - index);
            cout << s1 + s2 << endl;
        }
        else {
            cout << s.substr(0, have_odd_index + 1) << endl;
        }
        

    }
    return 0;
}