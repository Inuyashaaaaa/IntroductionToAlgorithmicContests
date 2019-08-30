#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 2e5;
int a[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n ;i++){
            cin >> a[i];
        }
        int minn = a[n - 1];
        int cnt = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(a[i] > minn) {
                cnt ++;
            }
            minn = min(a[i], minn);
        }
        cout << cnt << endl;
       
    }
    return 0;
}