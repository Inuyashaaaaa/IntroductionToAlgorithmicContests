#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
LL cnt = 0;


void merge(int left, int right) {
    int mid = (left + right) / 2;
    int num = right - left + 1;
    int count = 0;
    int *c = new int[maxn];
    int _left = left;
    int _right = mid + 1;
    while(_left <= mid && _right <= right) {
        if(a[_left] <= a[_right]) {
            c[count++] = a[_left];
            _left++;
        } else {
            c[count++] = a[_right];
            _right++;
            cnt += mid - _left + 1;
        }
    }
    while(_left <= mid) {
        c[count++] = a[_left];
        _left++;
    }
    while(_right <= right) {
        c[count++] = a[_right];
        _right++;
    }
    count = 0;
    for(int i = left; i <= right; i++) {
        a[i] = c[count++];
    }
    delete[] c;
}

void mergeSort(int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, right);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        mergeSort(0, n - 1);
        // for(int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        cout << cnt;
        cout << endl;
    }


    return 0;
}