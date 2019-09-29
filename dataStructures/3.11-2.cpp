#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 50;
/*
对于 100%的数据：1<=n<=100,000, 0<=w[i]<=10,000
*/
LL w[maxn];
LL tot[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        memset(tot, 0, sizeof(tot));
        for(int i = 0; i < n; i++) {
            cin >> w[i];
            if(i == 0) tot[i] = w[i];
            else tot[i] = tot[i - 1] + w[i];
        }      
        w[n] = 0;
        stack<int> s;
        LL better = 0;
        int i = 0;
        while(i <= n) {
            if(s.empty() || w[i] >= w[s.top()]) {
                s.push(i++);
            } 
            else {
                int tmp = s.top();
                s.pop();
                LL sum;
                if(s.empty()) 
                    sum = w[tmp] * tot[i - 1];
                else 
                    sum = w[tmp] * (tot[i - 1] - tot[s.top()]);
                better = max(better, sum);
            }
        }
        cout << better << endl;
    }
    return 0;
}