#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.get();
    string s;
    while(n--) {
        getline(cin, s);
        stack<char> ss;
        bool flag = true;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '[' || s[i] == '(')
                ss.push(s[i]);
            else if(s[i] == ']' && !ss.empty() && ss.top() == '[')
                ss.pop();
            else if(s[i] == ')' && !ss.empty() && ss.top() == '(')
                ss.pop();
            else {
                flag = false;
                break;
            }
        }
        cout << (flag && ss.size() == 0 ? "Yes" : "No") << endl;
    }
}