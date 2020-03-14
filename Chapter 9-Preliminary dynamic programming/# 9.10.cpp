#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
using std::cout;
const int INF = 100 + 10;
const int maxn = 1e2 + 10;
int d[maxn][maxn];
string s;

bool match(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')')
    || (ch1 == '[' && ch2 == ']');
}

void print(int l, int r) {
    if(l >= r) return;
    if(l + 1 == r) {
        if(s[l] == '(' || s[l] == ')') cout << "()";
        else cout << "[]";
        return;
    }
    if(match(s[l], s[r - 1]) && d[l][r] == d[l + 1][r - 1]) {
        cout << s[l];
        print(l + 1, r - 1);
        cout << s[r - 1];
        return;
    }
    for(int m = l + 1; m < r; m++) {
        if(d[l][r] == d[l][m] + d[m][r]) {
            // cout << "l:" << l << " r:" << r << " m:" << m << endl;
            print(l, m);
            print(m, r);
            return;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.get();
    while(n--) {
        getline(cin, s);
        getline(cin, s);
        if(s == " ") {
            cout << s << endl;
            if(n) cout << endl;
            continue;
        }
        int sz = s.size();
        for(int i = 0; i <= sz; i++) {
            for(int j = 0; j <= sz; j++) {
                d[i][j] = INF;
            }
        }
        for(int i = 0; i < sz; i++) {
            d[i][i + 1] = 1;
            d[i][i] = 0;
        }
        d[sz][sz] = 0;
        for(int len = 2; len <= sz; len++) {
            for(int l = 0; l + len <= sz; l++) {
                int r = l + len;
                if(match(s[l], s[r - 1])) d[l][r] = min(d[l + 1][r - 1], d[l][r]);
                for(int m = l + 1; m < r; m++) {
                    d[l][r] = min(d[l][r], d[l][m] + d[m][r]);
                }
                // cout << "d[" << l << "][" << r << "]: " << d[l][r] << endl; 
            }
        }
        // cout << 0 << ": " << sz << endl;
        print(0, sz);
        cout << endl;
        if(n) cout << endl;
    }
    return 0;
}