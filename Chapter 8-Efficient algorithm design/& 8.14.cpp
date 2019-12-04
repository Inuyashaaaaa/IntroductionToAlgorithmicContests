#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
const int m = 1e6 + 5;
const double exp1 = 1e-10;

struct Node {
    double l, r;
    friend bool operator < (const Node& n1, const Node& n2) {
        return n1.l < n2.l || (n1.l == n2.l && n1.r < n2.r);
    }
}node[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> node[i].l >> node[i].r;
        }
        sort(node, node + n);
        double l = 0;
        double r = m;
        double mid;
        while(l + exp1 < r) {
            mid = l + (r - l) / 2;
            bool ok = true;
            double cur = 0;
            for(int i = 0; i < n; i++) {
                if(cur < node[i].l) cur = node[i].l;
                if(cur + mid > node[i].r) {
                    ok = false;
                    break;
                }
                cur += mid;
            }
            if(ok) {
                l = mid;
            } else {
                r = mid;
            }
        }
        LL num = 0, den = 1;
        for(int tden = 1; tden <= n; ++tden) {
            LL tnum = round(mid * tden);
            if(fabs((double)tnum/tden - mid) < fabs((double)num/den - mid))
                num = tnum, den = tden;
        }
        cout << num << "/" << den << endl;
    }
    return 0;
}