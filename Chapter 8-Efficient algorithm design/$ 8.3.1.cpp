//递归与分治
//棋盘覆盖问题
//俺自己的数据和答案

/*
3
........
........
........
....*...
........
........
........
........

CCDDHHII
CBBDHGGI
EBFFJJGK
EEFA*JKK
MMNAARSS
MLNNRRQS
OLLPTQQU
OOPPTTUU

*/


#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1000;
char pic[maxn][maxn];
char cnt = 'A';

//[left, right)
void fill(int leftX, int leftY, int rightX, int rightY) {
    if(leftX == rightX - 1) return;
    int midX = leftX + (rightX - leftX) / 2;
    int midY = leftY + (rightY - leftY) / 2;
    for(int i = leftX; i < midX; i++) {
        for(int j = leftY; j < midY; j++) {
            if(pic[i][j] != '.') {
                pic[midX][midY - 1] = cnt;
                pic[midX][midY] = cnt;
                pic[midX - 1][midY] = cnt++;
                goto Part;
            }
        }
    }
    for(int i = midX; i < rightX; i++) {
        for(int j = leftY; j < midY; j++) {
            if(pic[i][j] != '.') {
                pic[midX][midY] = cnt;
                pic[midX - 1][midY] = cnt;
                pic[midX - 1][midY - 1] = cnt++;
                goto Part;
            }
        }
    }
    for(int i = midX; i < rightX; i++) {
        for(int j = midY; j < rightY; j++) {
            if(pic[i][j] != '.') {
                pic[midX][midY - 1] = cnt;
                pic[midX - 1][midY] = cnt;
                pic[midX - 1][midY - 1] = cnt++;
                goto Part;
            }
        }
    }
    for(int i = leftX; i < midX; i++) {
        for(int j = midY; j < rightY; j++) {
            if(pic[i][j] != '.') {
                pic[midX][midY - 1] = cnt;
                pic[midX][midY] = cnt;
                pic[midX - 1][midY - 1] = cnt++;
                goto Part;
            }
        }
    }
    Part:
    fill(leftX, leftY, midX, midY);
    fill(leftX, midY, midX, rightY);
    fill(midX, leftY, rightX, midY);
    fill(midX, midY, rightX, rightY);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < pow(2, n); i++) {
        cin >> pic[i];        
    }
    fill(0, 0, pow(2, n), pow(2, n));
    for(int i = 0; i < pow(2, n); i++) {
        cout << pic[i] << endl;
    }
    return 0;
}