#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1.3e6;
const int Mod = 5e4;
int n;
bool isPrime[maxn];

LL solve() {
    LL ret = 1;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    int cnt = 0;
    for(int i = 2; i < maxn; i++) {
        if(isPrime[i]) {
            ret *= i;
            ret %= Mod;
            cnt++;
            if(cnt == n) return ret;
            for(int j = i + i; j < maxn; j += i) {
                isPrime[j] = false;
            }
        }
        //cout << cnt << endl;
    }
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << solve() << endl;
    return 0;
}