#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        LL x, y, a, b;
        cin >> x >> y >> a >> b;
        LL d = y - x;
        if(d % (a + b) == 0) {
            cout << d / (a + b) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    // system("pause");
    return 0;
}