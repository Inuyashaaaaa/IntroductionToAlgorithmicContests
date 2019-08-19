#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

int a[maxn];
int b[maxn];
set<int> has;

int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
        has.insert(a[i]);
    }
    int m;
    cin >> m;
    for(int i = 0; i <m ; i++){
        cin >> b[i];    
        has.insert(b[i]);
    }


    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ;j ++) {
            int c = a[i] + b[j];
            if(has.count(c))
            continue;
            else{
                cout << a[i] << " " << b[j] << endl;
                 //system("pause");
                return 0;
            }
        }
    }
    
    //system("pause");
    return 0;
}