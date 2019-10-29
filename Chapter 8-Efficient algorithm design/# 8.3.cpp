#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;



int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while (T--) {
        if(kase++) cout << endl;
        int n;
        cin >> n;
        vector<int> s[4];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) {
                int x;
                cin >> x;
                s[j].push_back(x);
            }
        }
        unordered_map<int, int> m;
        for(auto& num1: s[0]) {
            for(auto& num2 : s[1]) {
                if(!m.count(num1 + num2)) 
                    m[num1 + num2] = 0;
                m[num1 + num2]++;
            }
        }
        LL ans = 0;
        for(auto& num1: s[2]) {
            for(auto& num2 : s[3]) {
                if(m.count(-(num1 + num2))) {
                    ans += m[-(num1 + num2)];
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}