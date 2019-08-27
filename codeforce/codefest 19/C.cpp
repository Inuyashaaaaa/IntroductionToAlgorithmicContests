#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n;i ++) {
        int mul = i / 4;
        mul *= (n / 4 - 1);
        int begin = i * 4 + mul * 16 - 1;
        for(int j = 0; j < n; j++) {
            if(j % 4 == 0 && j)
            begin+=13;
            else
            begin++;
            cout << begin << " ";
        }
        cout << endl;
    }
    return 0;
}