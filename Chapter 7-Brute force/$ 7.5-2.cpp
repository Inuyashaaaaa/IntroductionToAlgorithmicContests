#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n, L, cnt;
bool dfs(int cur, int* A) {
    if(cnt++ == n) {
        for(int i = 0; i < cur; i++) {
            if(i == 64) cout << endl;
            if(i && i % 4 == 0 && i != 64) cout << " ";
            cout << char(A[i] + 'A');
        }
        cout << endl;
        cout << cur << endl;
        return 0;
    }
    for(int i = 0; i < L; i++) {
        A[cur] = i;
        bool ok = true;
        for(int j = 1; 2 * j <= cur + 1; j++) {
            bool equal = true;
            for(int k = 0; k < j; k++) {
                if(A[cur - k] != A[cur - j - k]) {
                    equal = false;
                    break;
                }
            }
            if(equal) {
                ok = false;
                break;
            }
        }
        if(ok) {
            if(!dfs(cur + 1, A)) return 0;
        }
    }
    return 1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> L && n) {
        cnt = 0;
        int A[100];
        dfs(0, A);
    }    
    return 0;
}