#include<iostream>
using namespace std;
#define LL long long

const int maxn = 4e4;

LL a[maxn];
int v[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    for(LL i = 1; i < maxn; i++) {
        a[i] = i * (i - 1) / 2;
    }
    int T;
    cin >> T;
    while(T--) {
        LL n;
        cin >> n;
        int tn = 0;
        for(int i = maxn - 1;i && n; i--) {
            while(n >= a[i]){
                n -= a[i];
                v[++tn] = i; 
            }
        }
        v[tn + 1] = 0;
        for(int i = 1; i<= tn; i++) {
            cout << 1 ;
            for(int j = 0; j < v[i] - v[i + 1]; j++) cout << 3;
        }
        cout << 7 << endl;
    }
    return 0;
}
