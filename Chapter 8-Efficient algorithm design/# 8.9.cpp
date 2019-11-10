#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 5;
int sum[maxn];
string s;
int p[maxn];
int n, L;

int compare_average(int x1, int x2, int x3, int x4) {
    return (sum[x2] - sum[x1 - 1]) * (x4 - x3 + 1) - (sum[x4] - sum[x3 - 1]) * (x2 - x1 + 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> L;
        cin >> s;
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + s[i - 1] - '0';
        }
        int ansL = 1, ansR = L;

        // p[i...j) 
        int i = 0, j = 0;
        for(int t = L; t <= n; t++) {
            while(j - i > 1 && compare_average(p[j - 2], t - L, p[j - 1], t - L) >= 0) j--;
            p[j++] = t - L + 1;
            while(j - i > 1 && compare_average(p[i], t, p[i + 1], t) <= 0) i++;

            int c = compare_average(p[i], t, ansL, ansR);
            if(c > 0 || c == 0 && t - p[i] < ansR - ansL) {
                ansL = p[i];
                ansR = t;
            }
        }
        cout << ansL << " " << ansR << endl;
    }
    return 0;
}