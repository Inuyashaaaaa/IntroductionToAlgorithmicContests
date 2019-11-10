#include<bits/stdc++.h>
#define LL long long
#define INF 0x7fffffff
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 65536 + 1;
bool prime[maxn];

void getPrime() {
    prime[2] = true;
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            for(int j = 2 * i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
}

int get(int num) {
    unordered_set<int> s;
    while(num) {
        s.insert(num % 10);
        num /= 10;
    }
    return s.size();
}

bool check(int num,int i) {
    while(i) {
        if(num % 10 != i % 10) return false;
        num /= 10;
        i /= 10;
    }
    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL num;
    while(cin >> num && num) {
        int i = num;
        int minn = 6;
        int ans = num;
        int cnt = 0;
        while(1) {
            // cout << num << endl;
          	int d = get(num);
            if( d < minn) {
                ans = num;
                minn =  d;
              	if(minn == 1)
                  break;
            }
            num *= prime[i];
            if(num > INF) break;
        }
         if(get(num) < minn) {
                ans = num;
                minn = get(num);
        }
        cout << ans << endl;
    }
    return 0;
}