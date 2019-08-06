//Vijos 1056

#include<iostream>
#include<algorithm>
using namespace std;

const long long maxn = 100 + 5;

struct Rectangle {
    long long x1, y1; //左下角
    long long x2, y2; //右上角
}rec[maxn];

long long weight[2 * maxn][2 * maxn]; //每一块的面积
long long x[2 * maxn];
long long y[2 * maxn];
long long n;
long long haveFind[2 * maxn][2 *maxn];

int cover(double xc, double yc) {
    //判断中点是否覆盖
    long long cnt = 0;
    for(long long i = 0; i < n; i++) {
        if(rec[i].x1 < xc && rec[i].y1 < yc && rec[i].x2 > xc && rec[i].y2 > yc) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    cin >> n;
    
    long long ans = 0;
    for(long long i = 0; i < n; i++) {
        cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
        x[i * 2] = rec[i].x1;
        x[i * 2 + 1] = rec[i].x2;
        y[i * 2] = rec[i].y1;
        y[i * 2 + 1] = rec[i].y2;
        ans += (rec[i].x2 - rec[i].x1) * (rec[i].y2 - rec[i].y1);
    }

    //离散化
    sort(x, x + 2 * n);
    sort(y, y + 2 * n);

    long long size1 = unique(x, x + 2 * n) - x;
    long long size2 = unique(y, y + 2 * n) - y;
    
    for(long long i = 0; i < size1 - 1; i++) {
        for(long long j = 0; j < size2 - 1; j++) {
            // cout << x[i] << " " << y[j] << endl;
            weight[i][j] = (x[i+1] - x[i]) * (y[j+1] - y[j]);
            int cnt = cover((x[i]+x[i+1])/2.0,(y[j]+y[j+1])/2.0);
            ans -= weight[i][j] * (cnt - 1);
 
            
        }
    }

    // for(int i = 0; i < size1 - 1; i++) {
    //     for(int j = 0; j < size2 - 1; j++) {
    //         cout << weight[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    
    // for(int i = 0; i < size1 - 1; i++) {
    //     for(int j = 0; j < size2 - 1; j++) {
    //         cout << haveFind[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    system("pause");
    return 0;
}