#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 2e5 + 10;

string s[maxn];


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
        bool is0 = false;
        bool is1 = false;
        bool isConected = false;
        int left0 = 0;
        int right0 = 0;
        int left1 = 0;
        int right1 = 0;
        set<string> ss;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            ss.insert(s[i]);
            if(s[i][0] == '0' && s[i][s[i].size() - 1] == '0') {
                is0 = true;
            }
            if(s[i][0] == '1' && s[i][s[i].size() - 1] == '1') {
                is1 = true;
            }
            if(s[i][0] == '1' && s[i][s[i].size() - 1] == '0') {
                isConected = true;
                right0++;
            }
            if(s[i][0] == '0' && s[i][s[i].size() - 1] == '1') {
                isConected = true;
                left0++;
            }
        }
        if(isConected) {
            int cnt = abs(left0 - right0) / 2;
            int ans = 0;
            vector<int> vec;
            for(int i = 0; i < n; i++) {
                if(cnt == ans) break;
                if(s[i][0] == '0' && s[i][s[i].size() - 1] == '0') {
                    continue;
                }
                if(s[i][0] == '1' && s[i][s[i].size() - 1] == '1') {
                    continue;
                }
                if(s[i][0] == '1' && s[i][s[i].size() - 1] == '0') {
                    if(left0 < right0) {
                        reverse(s[i].begin(), s[i].end());
                        if(ss.count(s[i])) continue;
                        ans++;
                        vec.push_back(i + 1);
                    }
                }
                if(s[i][0] == '0' && s[i][s[i].size() - 1] == '1') {
                    if(left0 > right0) {
                        reverse(s[i].begin(), s[i].end());
                        if(ss.count(s[i])) continue;
                        ans++;
                        vec.push_back(i + 1);
                    }
                }
            }
            cout << cnt << endl;
            for(auto& num: vec) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            if(is0 && is1) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl << endl;
            }
        }
    
    }
    
    return 0;
}