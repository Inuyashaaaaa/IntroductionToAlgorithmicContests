#include<bits/stdc++.h>
#define LL long long
using namespace std;

bool Prime[100];
bool vis[50];
int n;

bool isPrime(int n) {
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
        return false;
    }
    return true;
}

void dfs(int cur, int* A) {
    if(cur == n && Prime[A[0] + A[n - 1]]) {
        for(int i = 0; i < n; i++) {
            if(i) cout << " " << A[i];
            else cout << A[i];
        }
        cout << endl;
        return;
    }
    for(int i = 2; i <= n; i++) {
        if(!vis[i] && (!cur || Prime[i + A[cur - 1]])) {
            vis[i] = 1;
            A[cur] = i;
            dfs(cur + 1, A);
            vis[i] = 0;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
   

    int A[20];
    A[0] = 1;
    for(int i = 1; i <= 50; i++) {
        Prime[i] = isPrime(i);
    }
    int kase = 0;
    while(cin >> n) {
        if(kase) cout << endl;
        cout << "Case " << ++kase << ":" <<endl;
        memset(vis, 0, sizeof(vis));
        dfs(1, A);
    }

    return 0;
}