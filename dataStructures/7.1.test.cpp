//给定长度为n（n<=1000000）的字符串，
//字符串仅由小写字母的前m（m<=6）个字符组成，
//请你计算出共有多少长度为k（k<=6）的不相同子串。

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e6;
const int Mod = 6;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        int w = rand() % maxn + 1;
        int m = rand() % Mod + 1;
        int k = rand() % Mod + 1;
        cout << w << " " << m << " " << k << endl;
        for(int i = 0; i < w; i++) {
            cout << char('a' + rand() % m);
        }
        cout << endl;
    }


    return 0;
}