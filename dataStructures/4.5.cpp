#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> s;
    queue<int> q;
    int n;
    cin >> n;
    int maxn = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while(!q.empty()) {
        //维护一个单调递增栈
        int x = q.front();
        q.pop();
        if(!s.empty()){
            while(s.top() <= x) {
                s.pop();
                if(s.empty()) {
                    break;
                }
            }
            if(s.empty()) {
                maxn = max(x, maxn);
            } else {
                maxn = max(x + s.top(), maxn);
            }
        }
        s.push(x);
    }
    cout << maxn << endl;
    return 0;
}