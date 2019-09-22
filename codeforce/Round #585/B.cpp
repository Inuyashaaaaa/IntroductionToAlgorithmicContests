#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

int num[maxn];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < 0) a[i] = 0;
        if(x > 0) a[i] = 1;
    }
    int neg = 0;
    int pos = 0;
    //长度
    for(int k = 1; k <= n; k++) {
        //起始位置
        //第一个
        int r = 1;
        for(int i = 0; i < k; i++) {
            if(!a[i]) r = !r;
        }
        if(r == 0) neg++;
        else pos++;
        //滑窗
        for(int i = k; i < n; i++) {
            if(!a[i - k]) r = !r;
            if(!a[i]) r = !r;
            if(r == 0) neg++;
            else pos++;
        }
    }
    cout << neg << " " << pos << endl;
    return 0;
}