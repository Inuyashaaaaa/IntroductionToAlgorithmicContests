#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 20;
int sum[maxn];

void build(int pos) {
    int x;
    cin >> x;
    if(x == -1)
    return;
    sum[pos] += x;
    build(pos - 1);
    build(pos + 1);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int kase = 0;
    int x; 
    while(cin >> x) {
        if(x == -1) 
        break;
        cout << "Case " << ++kase << ":" << endl;
        memset(sum, 0, sizeof(sum));
        int pos = maxn / 2;
        sum[pos] = x;
        build(pos - 1);
        build(pos + 1);
        int a = 0;
        while(!sum[a]) a++;
        cout << sum[a++];
        while(sum[a]) {
            cout << " " << sum[a];
            a++;
        }
        cout << endl << endl;
    }
    return 0;
}