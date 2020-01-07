#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL a, b;
    cin >> a >> b;
    a++;
    LL c[100];
    c[0] = 1;
    for(int i = 1; i <= 63; i++) {
        c[i] = c[i - 1] * 2;
    }
    LL sum[100];
    sum[0] = c[0];
    for(int i = 1; i <= 63; i++) {
        sum[i] = sum[i - 1] + c[i];
    }
    // for(int i = 0; i < 63; i++)
    // cout << sum[i] << endl;
    int i;
    for(i = 0; i <= 63; i++) {
        if(b <= sum[i]) {
            break;
        }
    } 
    int j;
    for(j = 0; j <= 63; j++) {
        if(a <= c[j]) {
            break;
        }
    }

    LL mod = a % (LL)(pow(2, j - 1));
    //cout << mod << endl;
    LL num = pow(2, i);
    //cout << num << endl;
    LL v = mod / num;
    //cout << v << endl;



    cout << "*" << pow(2, j - i - 1) + v - 1 << endl;

    
    //cout << i << endl;
    //cout << j << endl;
    //cout << ans << endl;
    return 0;
}