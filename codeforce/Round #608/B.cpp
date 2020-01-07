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
    string s;
    cin >> s;
    string temp = s;
    vector<int> ans;
    for(int i = 0; i < n - 1; i++) {
        if(temp[i] == 'W') {
            temp[i] = 'B';
            if(temp[i + 1] == 'W') {
                temp[i + 1] = 'B';
            } else {
                temp[i + 1] = 'W';
            }
            ans.push_back(i + 1);
        }
    }
    if(temp[n - 1] == 'B') {
        cout << ans.size() << endl;
        for(auto& num: ans) {
            cout << num << " ";
        }
        if(ans.size())
        cout << endl;
        return 0;
    }
    temp = s;
    ans.clear();
    for(int i = 0; i < n - 1; i++) {
        if(temp[i] == 'B') {
            temp[i] = 'W';
            if(temp[i + 1] == 'B') {
                temp[i + 1] = 'W';
            } else {
                temp[i + 1] = 'B';
            }
            ans.push_back(i + 1);
        }
    }
    if(temp[n - 1] == 'W') {
        cout << ans.size() << endl;
        for(auto& num: ans) {
            cout << num << " ";
        }
        if(ans.size())
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}