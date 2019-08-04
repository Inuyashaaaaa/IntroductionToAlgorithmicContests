#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100050;
typedef long long LL;

LL a[maxn];
int main() {
    int n;
    cin >> n;
    LL sum = 0;
    LL maxN = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxN = max(a[i], maxN);
        sum += a[i];
    }
    if(sum % 2 || (maxN > (sum - maxN))) 
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    //system("pause");
    return 0;
}

