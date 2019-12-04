#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        vector<string> vec;
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end());
        int sz = vec.size();
        s = vec[sz / 2 - 1];
        string ans = s;
        string ss = vec[sz / 2];
        sz = s.size();
        for(int i = sz - 2; i >= 0; i--) {
            s[i]++;
            s.resize(i + 1);
            if(s[i] > 'Z') continue;
            if(s < ss) {
                ans = s;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}