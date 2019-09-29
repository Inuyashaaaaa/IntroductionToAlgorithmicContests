#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++) 
        q.push(i);
    if(n == 1) {
        cout << "1" << endl;
        return 0;
    }
    vector<int> ans;
    while(q.size() != 1) {
        ans.push_back(q.front());
        q.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    cout << q.front() << endl;
    return 0;
}