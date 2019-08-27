#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int a[2000 + 10];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> m;
    int ans = n - 1;
    for(int i = 0; i < n ; i++) {
        bool isPrefix = true;
        for(int j = 0; j < i; j++) {
            m[a[j]]++;
            if(m[a[j]] == 2) {
                isPrefix = false;
                break;
            }
        }
        int suffix = n;
        for(int j = n - 1; j >= i; j--) {
            m[a[j]]++;
            if(m[a[j]] == 1) {
                suffix = j;
            } else {
                break;
            }
        }
        if(isPrefix)
        ans = min (ans, suffix - i);
        m.clear();
    }
    cout << ans << endl;
    return 0;
}