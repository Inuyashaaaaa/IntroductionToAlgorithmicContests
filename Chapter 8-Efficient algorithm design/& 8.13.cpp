#include<bits/stdc++.h>
#define LL long long
#define INF 0X7fffffff
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];
int b[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        int l = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]] = i;
        }
        memcpy(b, a, sizeof(a));
        int minCnt = INF;
        int cnt = 0;

        unordered_map<int, int> m2 = m;
        for(int l = 0; l < n; l++) {
            m = m2;
            memcpy(a, b, sizeof(a));
            cnt = 0;
            for(int i = 0; i < n; i++) {
                if(a[(l + i) % n] != i + 1) {
                    int v = a[(l + i) % n];
                    int pos = m[i + 1];
                    swap(a[(l + i) % n], a[pos]);
                    m[v] = pos;
                    m[i + 1] = i;
                    cnt++;
                }
            }
            // for(int i = 0; i < n; i++) {
            //     cout << a[(l + i) % n] << " ";
            // }
            // cout << endl;
            minCnt = min(minCnt, cnt);
        }
        for(int l = 0; l < n; l++) {
            m = m2;
            memcpy(a, b, sizeof(a));
            cnt = 0;
            for(int i = 0; i < n; i++) {
                if(a[(l + i) % n] != n - i) {
                   int v = a[(l + i) % n];
                    int pos = m[n - i];
                    swap(a[(l + i) % n], a[pos]);
                    m[v] = pos;
                    m[n - i] = n - i - 1;
                    cnt++;
                }
            }
            // for(int i = 0; i < n; i++) {
            //     cout << a[(l + i) % n] << " ";
            // }
            //cout << endl;
            minCnt = min(minCnt, cnt);
        }
        cout << minCnt << endl;

    }
    return 0;
}