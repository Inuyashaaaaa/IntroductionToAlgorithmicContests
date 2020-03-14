#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e5 + 10;
LL a[maxn];
LL b[maxn];
vector<LL> vec;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        vec.push_back(a[i] - b[i]);
    }
    sort(vec.begin(), vec.end());
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        if(vec[i] <= 0) {
            int d = abs(vec[i]);
            int p  = upper_bound(vec.begin(), vec.end(), d) - vec.begin();
            ans += n - p;
        }
        else {
            ans += n - 1 - i;
        }
    }
    cout << ans << endl;
    return 0;
}