#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
LL a[maxn];
LL sum[maxn];

//题目有误，当最大值相同时不是输出任意区间都可以的
//应该是输出最短的区间，长度相同时输出左端点最小的区间

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int kase = 0;
    while(cin >> n && n) {
        if(kase++) std::cout << endl;
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        a[n + 1] = -1;
        stack<LL> s;
        LL maxd = -1;
        int i = 1;
        int l = 1, r = n + 1;
        while(i <= n + 1) {
            if(s.empty() || a[s.top()] < a[i]) {
                s.push(i++);
            } else {
                int t = s.top();
                s.pop();
                LL e;
                if(s.empty()) {
                    e = a[t] * sum[i - 1];
                    if(e > maxd) {
                        l = 1;
                        r = i - 1;
                        maxd = e;
                    }
                } else {
                    e = a[t] * (sum[i - 1] - sum[s.top()]);
                    if(e > maxd ||
                    ((e == maxd) && (i - 2 - s.top() < r - l))) {
                        l = s.top() + 1;
                        r = i - 1;
                        maxd = e;
                    }
                }

            }
        }
        std::cout << maxd << endl;
        std::cout << l << " " << r << endl;
    }

    return 0;
}