// O(n) 
// 快速选择问题

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int a[maxn];
int k;

// [l, r]
void quickSort(int l, int r) {
	if (l >= r) return;
	int _left = l;
	int _right = r - 1;
	int base = a[r];
	while (_left != _right) {
		while (a[_left] <= base) {
			if (_left == _right) break;
			_left++;
		}
		while (a[_right] >= base) {
			if (_left == _right) break;
			_right--;
		}
		swap(a[_left], a[_right]);
	}
    if(a[_left] > a[r])
	swap(a[_left], a[r]);
    if(_left >= k)
	quickSort(l, _left);
    else
	quickSort(_right + 1, r );
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> k;
        k--;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        quickSort(0, n - 1);
        // for (int i = 0; i < n; i++) {
        // 	cout << a[i] << " ";
        // }
        cout << a[k] << endl;
    }
	return 0;
}