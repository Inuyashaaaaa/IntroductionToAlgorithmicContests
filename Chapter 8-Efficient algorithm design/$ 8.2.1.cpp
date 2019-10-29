//O(nlogn)
//逆序对与归并排序

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int b[maxn];
int ans = 0;

// [left, right)
void mergeSort(int left, int right) {
    if(left == right - 1) return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    int _left = left;
    int _right = mid;
    int cnt = 0;
    while(_left < mid && _right < right) {
        if(a[_left] < a[_right]) {
            b[cnt++] = a[_left++]; 
        } else {
            b[cnt++] = a[_right++];
            ans += mid - _left; //逆序对加上
        }
    }
    while(_right < right) {
        b[cnt++] = a[_right++];
        ans += mid - _left; //逆序对加上
    }
    while(_left < mid) {
        b[cnt++] = a[_left++];
    }
    cnt = 0;
    for(int i = left; i < right; i++) {
        a[i] = b[cnt++];
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(0, n);
    cout << ans << endl;
    return 0;
}