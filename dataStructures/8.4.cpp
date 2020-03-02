#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

//Huffman

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, x;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> pq;
    for(int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    double ans = 0 ;
    while(pq.size() != 1) {
        double a = pq.top();
        pq.pop();
        double b = pq.top();
        pq.pop();
        pq.push(a + b);
        cout << (a + b) << endl;
        // ans += a + b;
    }
    // cout << ans << endl;
    return 0;
}