//Vijos 1056

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;

struct Rectangle {
    int x1, y1; //左下角
    int x2, y2; //右上角
}rec[maxn];

int weight[2 * maxn][2 * maxn]; //每一块的面积
int x[2 * maxn];
int y[2 * maxn];
int n;

bool cover(double xc, double yc) {
    //判断中点是否覆盖
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(rec[i].x1 < xc && rec[i].y1 < yc && rec[i].x2 > xc && rec[i].y2 > yc) {
            cnt++;
            if(cnt >= 2)
            return true;
        }
    }
    return false;
}

int main() {

    cin >> n;
    
    long long ans = 0;
    for(int i = 0; i < n; i++) {
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

    

    int size1 = unique(x, x + 2 * n) - x;
    int size2 = unique(y, y + 2 * n) - y;
    
    for(int i = 0; i < size1 - 1; i++) {
        for(int j = 0; j < size2 - 1; j++) {
            cout << x[i] << " " << y[j] << endl;
            weight[i][j] = (x[i+1] - x[i]) * (y[j+1] - y[j]);
            if(cover((x[i]+x[i+1])/2.0,(y[j]+y[j+1])/2.0)) {
                ans -= weight[i][j];
            }
        }
    }

    cout << ans << endl;
    //system("pause");
    return 0;
}