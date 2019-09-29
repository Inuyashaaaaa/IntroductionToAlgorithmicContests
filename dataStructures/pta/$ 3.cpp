#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++) {
        num = 0;
        string s;
        cin >> s;
        int len = s.size();
        bool judge = true;
        for(int j = 0; j < len; j++) {
            if(s[j] == 'S') num++;
            if(s[j] == 'X') num--;
            if(num > m || num < 0) {
                judge = false;
                break;
            }
        }
        if(num) judge = false;
        cout << (judge ? "YES" : "NO") << endl; 
    }
    return 0;
}