#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> s;
    int n, x;
    cin >> n;
    string ss;
    while(n--) {
        cin >> ss;
        if(ss[0] == 'I') {
            cin >> x;
            s.push(x);
        }
        if(ss[0] == 'P') {
            if(s.empty()) continue;
            s.pop();
        }
        if(ss[0] == 'A') {
            if(s.size() < 2) continue;
            int a1 = s.top();
            s.pop();
            int a2 = s.top();
            s.pop();
            s.push(abs(a1 - a2));
        }
        if(ss[0] == 'C') {
            if(s.empty()) continue;
            s.push(s.top());
        }
    }
    LL sum = 0;
    LL e = 0;
    while(!s.empty()) {
        e = s.top();
        sum += e;
        s.pop();
    }
    cout << sum << endl;
    return 0;
}