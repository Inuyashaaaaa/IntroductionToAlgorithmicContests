#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int n;
string get(string s, int k) {
    string prefix = s.substr(k - 1, n - k + 1);
    string suffix = s.substr(0, k - 1);
    if((n - k + 1 ) % 2 == 1) {
        reverse(suffix.begin(), suffix.end());
    }
    return prefix + suffix;

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> n >> s;
        int val = 1;
        string ans = s;
        for(int k = 2; k <= n; k++) {
            string sss = get(s, k);
            if(sss < ans) {
                ans = sss;
                val = k; 
            }
        }
        cout << ans << endl;
        cout << val << endl;
    }
    return 0;
}