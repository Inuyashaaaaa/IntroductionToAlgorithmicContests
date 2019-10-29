//O(logn)
//lower_bound
//upper_bound
//内部代码实现

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int n;

int lowerBound(int num) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int mid = left + (right - left) / 2; 
        if(a[mid] >= num) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int upperBound(int num) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int mid = left + (right - left) / 2; 
        if(a[mid] <= num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = lowerBound(2);
    int r = upperBound(2);
    // 这样得到了区间
    cout << "[" << l << "," << r << ")" << endl;

    return 0;
}