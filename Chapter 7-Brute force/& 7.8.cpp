#include<bits/stdc++.h>
#define LL long long
using namespace std;

int cnt = 0;
int n;

void search(int cur, int* A) {
    if(cur == n) {
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        bool ok = 1;
        A[cur] = i;
        for(int j = 0; j < cur; j++) {
            if(A[j] == i || cur - A[cur] == j - A[j]
            || cur + A[cur] == j + A[j]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            search(cur + 1, A);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    int ans[20];
    for(int i = 1; i <= 10; i++) {
        n = i;
        cnt = 0;
        int A[20];
        search(0, A);
        ans[i] = cnt;
    }
    cin.tie(0);
    while(cin >> n && n) {
        cout << ans[n] << endl;
    }
    return 0;
}