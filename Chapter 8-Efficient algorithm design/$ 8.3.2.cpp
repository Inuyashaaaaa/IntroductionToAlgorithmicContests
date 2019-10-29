// 循环日程表问题
/*
3

1 2 3 4 5 6 7 8 
2 1 4 3 6 5 8 7 
3 4 1 2 7 8 5 6 
4 3 2 1 8 7 6 5 
5 6 7 8 1 2 3 4 
6 5 8 7 2 1 4 3 
7 8 5 6 3 4 1 2 
8 7 6 5 4 3 2 1 

*/

#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 4;
int calendar[maxn][maxn];

//[left, right)
void fill(int left, int right) {
    if(left == right - 1) {
        calendar[left][left] = 1;
        return;
    }
    int mid = left + (right - left) / 2;
    fill(0, mid);
    for(int i = mid; i < right; i++) {
        for(int j = mid; j < right; j++) {
            calendar[i][j] = calendar[i - mid][j - mid];
        }
    }
    for(int i = mid; i < right; i++) {
        for(int j = 0; j < mid; j++) {
            calendar[i][j] = calendar[i - mid][j] + mid;
        }
    }
    for(int i = 0; i < mid; i++) {
        for(int j = mid; j < right; j++) {
            calendar[i][j] = calendar[i][j - mid] + mid;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fill(0, pow(2, n));
    for(int i = 0; i < pow(2, n); i++) {
        for(int j = 0; j < pow(2, n); j++) {
            cout << calendar[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}