#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
int n, k;
const int maxn = 5e2 + 10;
int a[maxn];
//10000000

bool check(int v) {
    int cnt = 0;
    int sum = 0;
    //cout << v << endl;
    for(int i = 0; i < n; i++) {
        //cout << sum << " ";
        if(a[i] > v) return true; //单个都大于这个值了 不可能 v要大
        sum += a[i];
        if(sum > v) {
            cnt++;
            sum = a[i];
        }
    }
    //cout << endl;
    return cnt >= k; // true 代表 v要大
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        LL r = 0;
        LL l = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            r += a[i];
        }
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        LL sum = 0;
        list<int> lis;
        bool flag = false;
        for(int i = n - 1; i >= 0; i--) {
            sum += a[i];
            if(sum > l && !flag) {
                k--;
                i++;
                sum = 0;
                if(i)
                lis.push_front(-1);
                continue;
            }
            if(k - 1 == i) {
                flag = true;
                --k;
                lis.push_front(a[i]);
                if(i)
                lis.push_front(-1);
                continue;
            }

            lis.push_front(a[i]);
        }
        bool begin = true;
        for(auto& num: lis) {
            if(!begin) cout << " ";
            if(num == -1) cout << "/";
            else cout << num;
            begin = false;
        }
        cout << endl;
    }
    
    return 0;
}