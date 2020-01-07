#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 5e6 + 10;
const int MOD = 2013;
LL fib[maxn];
struct node {
    int a, b;
    int pos;
    node(int a, int b, int pos): a(a), b(b), pos(pos){}
    node(){}
    friend bool operator < (const node& n1, const node& n2) {
        return n1.a != n2.a || n1.b != n2.b;
    }
};

set<node> ss;


/*
F（n）=AF（n-1）+BF（n-2）（n>=2且n为整数） F（0）= F（1）=1。
n <= 100000000 MOD 2013
*/

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL a, b, t;
    cin >> t >> a >> b;
    fib[0] = fib[1] = 1;
    ss.insert(node(1, 1, 1));
    int circle;
    int first;
    for(int i = 2; i <= maxn; i++) {
        fib[i] = (a * fib[i - 1] + b * fib[i - 2]) % MOD;
        //cout << fib[i] << " " << fib[i - 1] << endl;
        node n(fib[i - 1], fib[i], i);
        if(ss.count(n)) {
            // cout << fib[i - 1] << " " << fib[i] << endl;
            // cout << ss.find(n) -> a << " " << ss.find(n) -> b << endl;
            first = ss.find(n) -> pos;
            circle = i - ss.find(n) -> pos;
            //cout << first << " " << circle << endl;
            break;
        }
        ss.insert(n);
    }
    while(t--) {
        cin >> a;
        if(a <= first) cout << fib[a] << endl;
        else {
            a = (a - first) % circle + first;
            cout << fib[a] << endl;
        }
    }
    return 0;
}