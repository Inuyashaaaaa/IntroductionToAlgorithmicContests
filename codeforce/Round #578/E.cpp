//while (S[j] != s[k + 1] && k) k = f[k];

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1000;

int N = 0;
int prefix[maxn];
char s[maxn];
char S[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  
    int n;
    cin >> n;
    while(n--){
        int k = 0;
        cin >> s + 1;
        int len = strlen(s+1);
        for(int i = 2; i <= len; i++) {
            while(s[i] != s[k+1] && k) k = prefix[k];
            if(s[i] != s[k+1]) {
                prefix[i] = 0;
            }else {
                k++;
                prefix[i] = k;
            }
        }
        int j = max(1, N - len + 1);
        k = 0;
        for( ; j <= N; j++) {
            while(s[k+1] != S[j] && k) k = prefix[k];
            if(s[k+1] != S[j]) {
                k = 0;
            }else {
                k ++;
            }
        }
        for(k++; k <=len ;k ++) {
            S[++N] = s[k];
        }

    }
    for(int i = 1;i <=N;i++) cout << S[i];
    //system("pause");
}