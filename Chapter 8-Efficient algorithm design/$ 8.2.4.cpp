//O(logn)
//BinarySearch
//二分查找

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int n;

int binarySearch(int num) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(a[mid] == num) {
            return mid;
        }
        else if(a[mid] > num) {
            right = mid;
        } 
        else {
            left = mid + 1;
        }
    }
    return -1;
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
    cout << binarySearch(4) << endl;
    cout << binarySearch(-1) << endl;
    return 0;
}