#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5000 + 100;

struct rect {
    int lx, ly;     //  左上角
    int rx, ry;     //  右下角
    int xd, yd;
    int posx, posy; //  记录一下这个矩形里面如何放
    int id;
}r[maxn];

bool cmp1(rect& r1, rect& r2) {
    return r1.rx == r2.rx ? r1.xd > r2.xd : r1.rx < r2.rx; 
}

bool cmp2(rect& r1, rect& r2) {
    return r1.ry == r2.ry ? r1.yd > r2.yd : r1.ry < r2.ry;
}

bool cmp3(rect& r1, rect& r2) {
    return r1.id < r2.id;
}

int x[maxn];    //记录哪些 x 放过了
int y[maxn];    //记录哪些 y 放过了


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n) {
        ms(x);
        ms(y);
        for(int i = 0; i < n; i++) {
            cin >> r[i].lx >> r[i].ly >> r[i].rx >> r[i].ry;
            r[i].xd = r[i].rx - r[i].lx;
            r[i].yd = r[i].ry - r[i].ly;
            r[i].id = i;
        }
        sort(r, r + n, cmp1);
        for(int i = 0; i < n; i++) {
            int xx = r[i].lx;
            int xe = r[i].rx;
            bool flag = false;
            for(int j = xx; j <= xe; j++) {
                if(!x[j]) {
                    r[i].posx = j;
                    flag = true;
                    x[j] = true;
                    break;
                }
            }
            if(!flag) {
                goto END;
            }

        }
        sort(r, r + n, cmp2);
        for(int i = 0; i < n; i++) {
            int yy = r[i].ly;
            int ye = r[i].ry;
            bool flag = false;
            for(int j = yy; j <= ye; j++) {
                if(!y[j]) {
                    r[i].posy = j;
                    flag = true;
                    y[j] = true;
                    break;
                }
            }
            if(!flag) {
                goto END;
            }
        }
        sort(r, r + n, cmp3);
        for(int i = 0; i < n; i++) {
            cout << r[i].posx << " " << r[i].posy << endl;
        }
        continue;
        END: 
            cout << "IMPOSSIBLE " << endl;
    }
    return 0;
}