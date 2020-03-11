#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n;

void search(int cur, int* A) {
    if(cur == n) {
        for(int i = 0; i < n; i++) {
            cout << "(" << i + 1 << "," 
            << A[i] << ")"; 
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        A[cur] = i;
        for(int j = 0; j < cur; j++) {
            if( A[cur] == A[j] || A[cur] + cur == A[j] + j ||
            A[cur] - cur == A[j] - j) {
                ok = false;
                break;
            }
        }
        if(ok)
            search(cur + 1, A);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = 8;
    int A[10];
    search(0, A);
    return 0;
}