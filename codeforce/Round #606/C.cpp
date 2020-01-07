#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
const int maxn = 2e5 + 10;
bool vis[maxn];
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
        int sz = s.size();
        vector<int> vec;
        ms(vis);
        for(int i = 0; i < sz - 2; i++) {
            //cout << s[i];
            if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'
            && !vis[i] && !vis[i + 1] && !vis[i + 2]) {
                vec.push_back(i + 1);
                vis[i + 1] = true;
            }
            if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'
            && !vis[i] && !vis[i + 1] && !vis[i + 2]) {
                if(i + 4 < sz && s[i + 3] == 'n' && s[i + 4] == 'e') {
                    vec.push_back(i + 2);
                    vis[i + 2] = true;
                }
                else {
                    vec.push_back(i + 1);
                    vis[i + 1] = true;
                }
                
            }
        }
        cout << vec.size() << endl;
        for(auto& num: vec) {
            cout << num + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}