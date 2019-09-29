#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> a;
    queue<int> b;
    vector<int> ans;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x % 2 == 1) a.push(x);
        else b.push(x);
    }
    while(!a.empty() || !b.empty()) {
        if(!a.empty()) {
            ans.push_back(a.front());
            a.pop();
        }
        if(!a.empty()) { 
            ans.push_back(a.front());
            a.pop();
        }
        if(!b.empty()) {
            ans.push_back(b.front());
            b.pop();
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    return 0;
}