#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 50;
int a[50];
int b[50];

bool cmp(int& a, int& b) {
    return a > b;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        int x;
        int cnt = 0;
        while(ss >> x) {
            a[cnt] = x;
            b[cnt++] = x;
        }
        for(int i = 0; i < cnt; i++) {
            if(i) cout << " ";
            cout << a[i];
        }
        cout << endl;
        sort(b, b + cnt , cmp);
        int cnt2 = 0;
        for(int j = 0; j < cnt; j++) {
            for(int i = 0; i < cnt - j; i++) {
                if(b[j] == a[i]) {
                    if(i == cnt - j - 1) break;
                    if(i == 0) {
                        reverse(a, a + cnt - j);
                        cout << j + 1 << " ";
                        break;
                    }
                    reverse(a, a + i + 1);
                    cout << cnt - i << " ";
                    reverse(a, a + cnt - j);
                    cout << j + 1 << " ";
                }
            }
        }
        cout << 0 << endl;
    }
    return 0;
}