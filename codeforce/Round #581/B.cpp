#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, l, r;
    cin >> n >> l >> r;
    int oneCnt = n - l;
    int BigCnt = n - r;
    int minSum = oneCnt;
    int maxSum = 0;
    for(int i = 1,cnt = 1; i <=l; i++) {
        minSum += cnt;
        cnt *= 2;
    }
    int cnt = 1;
    for(int i = 1; i <= r; i++) {
        maxSum += cnt;
        cnt *= 2;
    }
    cnt /= 2;
    maxSum += BigCnt * cnt;
    cout << minSum << " " << maxSum << endl;
}