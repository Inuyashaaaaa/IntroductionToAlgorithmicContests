#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e4;
int a[4];
int pos[maxn];
int t = 0;


void move(int k, int cnt) {
    for(int i = 0; i < cnt; i++) {
        pos[t] =  pos[t - 1] + k;
        t++;
    }
    a[abs(k)] -= cnt;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        pos[0] = 0;
        t = 1;     
        cin >> a[1] >> a[2] >> a[3];
        int n = a[1] + a[2] + a[3];
        // cout << n << " ";
        int k = a[3] / 3;
        switch (a[3] % 3) {
        case 0:
            move(3, k);
            move(1, 1);
            move(-3, k);
            move(1, 1);
            move(3, k);
            break;
        case 1:
            move(3, k + 1);
            //if(a[2])
            move(-2, 1);
            //else
            //move(-1, 2);
            move(-3, k);
            move(1, 1);
            move(3, k);
            //if(a[2])
            move(2, 1);
            //else
            //move(1, 2);
            break;
        case 2:
            move(3, k + 1);
            move(-1, 1);
            move(-3, k);
            move(-1, 1);
            move(3, k + 1);
            break;
        }
        move(1, a[1] - 1);
        k = (a[2] + 1) / 2;
        move(2, k);
        if(a[2] == k) move(1, 1);
        else move(-1, 1);
        move(-2, a[2]);

        for(int i = 0; i < t; i++) {
            if(i) cout << " ";
            cout << pos[i];
        }
        cout << endl;
    }
    return 0;
}