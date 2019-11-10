#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            pq.push(x);
        }
        LL sum = 0;
        while(pq.size() != 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a + b;
            pq.push(a + b);
        }
        cout << sum << endl;
    }
    return 0;
}