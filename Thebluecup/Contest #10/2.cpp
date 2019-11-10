#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define INT_MAX 0x7fffffff
using namespace std;


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<int> vec;
    while(cin >> s) {
        LL ans = 0;
        int sz = s.size();
        bool flag = true;
        bool judge = false;
        for(int i = 0; i < sz; i++) {
            if(isdigit(s[i])) {
                judge = true;
                ans *= 10;
                ans += s[i] - '0';
                if(ans > INT_MAX) {
                    flag = false;
                }
            } else {
                if(!judge) continue;
                if(flag) vec.push_back(ans);
                else vec.push_back(-1);
                flag = true;
                ans = 0;
                judge = false;
            }
        }
        if(judge) {
            if(flag) vec.push_back(ans);
                else vec.push_back(-1);
        }
    }
    for(int i = 0; i < vec.size(); i++) {
        if(i) cout << " ";
        if(vec[i] == -1) cout << "overflow";
        else cout << vec[i];
    }
    return 0;
}