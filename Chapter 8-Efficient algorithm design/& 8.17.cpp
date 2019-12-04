#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6 + 10;
const int maxc = 1e3 + 10;
int a[maxn];
int N, M, K;

bool check(int t) {
    int tot = 0;
    int cnt[maxc];
    ms(cnt);
    for(int i = 1; i <= N; i++) {
        if(tot == K) return true;
        if(a[i] <= K && cnt[a[i]]++ == 0) tot++;
        if(i > t && a[i - t] <= K && --cnt[a[i - t]] == 0) tot--;
    }
    if(tot == K) return true;
    return false;
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int kase = 0;
    while(T--) {
        cin >> N >> M >> K;
        a[1] = 1; a[2] = 2; a[3] = 3;
        for(int i = 4; i <= N; i++) {
            a[i] = (a[i - 3] + a[i - 2] + a[i - 1]) % M + 1;
        }
        int L = 1, R = N + 1;
        while(L < R) {
            int Mid = L + (R - L) / 2;
            if(check(Mid)) {
                R = Mid;
            } else {
                L = Mid + 1;
            }
        }
        //cout << L << endl;
        if(check(L)) cout << "Case " << ++kase << ": " << L << endl;
        else cout << "Case " << ++kase << ": " <<"sequence nai" << endl;
    }
    return 0;
}