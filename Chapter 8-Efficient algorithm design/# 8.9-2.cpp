#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn];
int p[maxn];

double compare(int x1, int x2, int x3, int x4) {
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
        int n, L;
        cin >> n >> L;
        char s[maxn];
        cin >> (s + 1);
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + s[i] - '0';
        }
        int i = 0; //切点 
        int j = 0; //j是离r L位置
        // r 是当前位置
        int ansL = 1;
        int ansR = L;
        for(int r = L; r <= n; r++) {
            while(j - i > 1 && compare(p[j - 2], r - L, p[j - 1], r - L) >= 0) j--;
            p[j++] = r - L + 1;
            while(j - i > 1 && compare(p[i], r, p[i + 1], r) <= 0) i++;
            int c = compare(p[i], r, ansL, ansR);
            if(c > 0 || c == 0 && r - p[i] < ansR - ansL) {
                ansL = p[i];
                ansR = r;
            }
        }
        cout << ansL << " " << ansR << endl;

    }
    return 0;
}