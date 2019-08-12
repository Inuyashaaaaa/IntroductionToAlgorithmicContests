#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e6 + 1000;
char s[maxn];
int prefix[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> s + 1) {
        if(s[1] == '.')
        break;
        int k = 0;
        int len = strlen(s+1);
        for(int i = 2; i <= len; i ++ ){
            while(s[i] != s[k + 1] && k) k = prefix[k];
            if(s[i] != s[k+1]) {
                prefix[i] = 0;
            }else {
                k++;
                prefix[i] = k;
            }
        }
        // for(int i = 1; i <= len; i++) {
        //     cout << i << ":" << prefix[i] << endl;
        // }
        int n = len - prefix[len];
        if(len%n == 0)
            cout << len / n <<endl;
        else
            cout << 1 << endl;
    }
}
