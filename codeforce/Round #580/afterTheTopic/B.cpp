#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x; 
    int zeroCnt = 0;
    int nagCnt = 0;
    long long coins = 0;
    for(int i = 0 ;i < n ; i++) {
        cin >> x;
        if(x < 0 ) {
            coins += (-1 - x);
            nagCnt++;
        }
        if(x > 0) {
            coins += (x - 1);         
        }
        if(x == 0) {
            zeroCnt ++;
        }
    }
    if(nagCnt % 2 == 1) {
        if(zeroCnt) {
            zeroCnt--;
            coins++;
        }else {
            coins+= 2;
        }
    }
    coins += zeroCnt;
    cout << coins << endl;
} 