#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 100 + 10;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> vec;
    for(int i = 0; i < n ;i++) {
        if(a[i] % b != 0) {
            vec.push_back(a[i]);
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        if(i) cout << " ";
        if(vec[i] <= 'Z' && vec[i] >= 'A') {
            cout << char(vec[i]);
        } else 
        {
            cout << vec[i];
        }
    }

    return 0;
}