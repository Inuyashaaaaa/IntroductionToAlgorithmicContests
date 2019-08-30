#include<bits/stdc++.h>
using namespace std;

bool check(int a, int b) {
    bool vis[10];
    memset(vis, false, sizeof(vis));
    if(a < 10000 || b < 10000) 
        vis[0] = true;
    while(a) {
        vis[a % 10] = true;
        a /= 10;
    }
    while(b) {
        vis[b % 10] = true;
        b /= 10;
    } 
    for(int i = 0; i < 10; i++)
        if(!vis[i])
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int j, n;
    int kase = 0;
    while(cin >> n && n) {
        if(kase++)  cout << endl;
        bool haveSolution = false;
        for(int i = 1234; i <= 98765; i ++) {          
            j = i / n;
            if(check(i, j) && i % n == 0){
                haveSolution = true;
                cout << setfill('0') << setw(5) << i << 
                " / " << setw(5) <<  j << " = " << n << endl; 
            }
        }
        if(!haveSolution)
        cout << "There are no solutions for " << n << "." << endl;
    }
    return 0;
}