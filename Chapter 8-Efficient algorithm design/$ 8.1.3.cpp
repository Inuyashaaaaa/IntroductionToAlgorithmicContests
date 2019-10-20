//O(nlogn)
//最大连续和

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int best;

// 区间 s[left, right)
int solve(int left, int right) {
    //递归到底
    if(left == right - 1) return a[left];

    //折中
    int mid = left + (right - left) / 2;
    //拆分
    int maxs = max(solve(left, mid), solve(mid, right));
    //合左
    int v, L, R;
    v = 0; L = a[mid - 1];
    for(int i = mid - 1; i >= left; i--) {
        L = max(L, v += a[i]);
    }
    //合右
    v = 0; R = a[mid];
    for(int i = mid; i < right; i++) {
        R = max(R, v += a[i]);
    }
    //要么是左，要么是右， 要么是整段区间
    return max(maxs, L + R);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    best = a[1];
    cout << solve(1, n + 1) << endl;
    return 0;
}