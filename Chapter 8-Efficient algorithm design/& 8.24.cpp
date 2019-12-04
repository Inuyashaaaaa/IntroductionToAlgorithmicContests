#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 4e3;
const int center = 2e3;
int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    while(cin >> l >> r && l && r) {
        l += center;
        r += center;
        for(int i = l ; i <= r; i += 2) {
            cin >> a[i];
        }
        int lmax = -1;
        int lnum = 0;
        int lindex;
        bool rflag = false;
        int rflagindex;
        for(int i = l; i <= r; i += 2) {
            if(i >= center && a[i] >= lmax) {
                if(a[i] == lmax) {
                    rflag = true;
                    rflagindex = i;
                }
                break;
            }
            if(a[i] >= lmax) {
                lmax = a[i];
                lindex = i;
            }
            lnum += lmax * 2;
        }
        int rmax = -1;
        int rnum = 0;
        int rindex;
        bool lflag = false;
        int lflagindex;
        for(int i = r; i >= l; i -= 2) {
            if(i <= center && a[i] >= rmax) {
                if(a[i] == rmax) {
                    lflag = true;
                    lflagindex = i;
                }
                break;
            }
            if(a[i] >= rmax) {
                rmax = a[i];
                rindex = i;
            }
            rnum += rmax * 2;
        }  
        if(rmax == lmax) {
            int ans = min(rnum, lnum);
            int lmax = -1;
            int lnum = 0;
            for(int i = l; i < lindex; i += 2) {
                if(a[i] >= lmax) {
                    lmax = a[i];
                }
                lnum += lmax * 2;
            }
            int rmax = -1;
            int rnum = 0;
            for(int i = r; i > rindex; i -= 2) {
                if(a[i] > rmax) {
                    rmax = a[i];
                }
                rnum += rmax * 2;
            }
            cout << ans + min(rnum, lnum) << endl;
        } else {
            if(rmax > lmax) {
                int ans = lnum;
                if(rflag) {
                    int lmax = -1;
                    int lnum = 0;
                    for(int i = l; i < lindex; i+=2) {
                        if(a[i] >= lmax) {
                            lmax = a[i];
                        }
                        lnum += lmax * 2;
                    }
                    int rnum = 0;
                    rnum = (rindex - rflagindex) * a[lindex];
                    if(rnum > lnum) ans += lnum;
                    else ans += rnum; 
                } 
                cout << ans << endl;        
            } else {
                int ans = rnum;
                if(lflag) {
                    int rmax = -1;
                    int rnum = 0;
                    for(int i = r; i > rindex; i -= 2) {
                        if(a[i] > rmax) {
                            rmax = a[i];
                        }
                        rnum += rmax * 2;
                    }
                    int lnum = 0;
                    lnum = (lflagindex - lindex) * a[rindex];
                    if(lnum > rnum) ans += rnum;
                    else ans += lnum; 
                } 
                cout << ans << endl;
            }
        }

    }
    return 0;
}