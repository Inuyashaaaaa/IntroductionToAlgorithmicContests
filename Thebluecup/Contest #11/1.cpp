#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;
char a[maxn];
char b[maxn];
int a1[maxn], b1[maxn], c1[maxn];
int len1, len2;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    ms(a1);
    ms(b1);
    ms(c1);
    len1 = strlen(a);
    len2 = strlen(b);
    for(int i = 0; i < len1; i++) {
        a1[len1 - 1 - i] = a[i] - '0';
    }
    for(int i = 0; i < len2; i++) {
        b1[len2 - 1 - i] = b[i] - '0';
    }
    int maxd = max(len1, len2);
    int e = 0;
    for(int i = 0; i < maxd; i++) {
        c1[i] = (a1[i] + b1[i] + e) % 10;
        e = (a1[i] + b1[i] + e) / 10;
    }
    if(e > 0) {
        cout<< e;
    }
    for(int i = maxd - 1; i >= 0; i--) {
        cout << c1[i];
    }
    return 0;
}