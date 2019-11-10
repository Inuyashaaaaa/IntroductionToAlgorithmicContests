#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 3.1e4 + 10;
int low[maxn];
int arr[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    low[1] = arr[1];
    int len = 1;
    for(int i = 2; i <= n; i++) {
        if(arr[i] >= low[len]) {
            low[++len] = arr[i];
        } else {
            int pos = upper_bound(low + 1, low + len + 1, arr[i]) - low;
            if(low[pos] >= arr[i]) {
                low[pos] = arr[i];
            }
        }
    }
    cout << len << endl;
    return 0;
}