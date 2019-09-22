#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    stack<int> ss;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s[0] == 'I') {
            int x;
            cin >> x;
            ss.push(x);
        }
        if(s[0] == 'P') {
            if(!ss.empty()) {
                ss.pop();
            }
        }
        if(s[0] == 'A') {
            if(ss.size() >= 2) {
                int x = ss.top();
                ss.pop();
                int y = ss.top();
                ss.pop();
                ss.push(abs(x - y));
            }
        }
        if(s[0] == 'C') {
            if(!ss.empty()) {
                int x = ss.top();
                ss.push(x);
            }
        }
    }
    LL sum = 0;
    while(!ss.empty()) {
        sum += ss.top();
        ss.pop();
    }
    cout << sum << endl;
    return 0;
}