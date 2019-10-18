#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 20 + 5;

int n;
int k;
char pic[maxn][maxn];
char ans[maxn][maxn];

bool dfs(int id, char ch) {
    while(ans[id / n][id % n] != '.') id++;
    //cout << id << endl;
    //cout << n << endl;
    if(id == n * n) return true;
    int r = id / n;
    int c = id % n;
    int ec = n;
    for(int i = r; i < n; i++) {
        for(int j = c; j < ec; j++) {
            if(ans[i][j] != '.') {
                ec = j;
                break;
            }
            int sum = (i - r + 1) * (j - c + 1);
            if(sum > 9) {
                ec = j;
                break;
            }
            int digit = 100;
            bool valid = true;
            for(int k = r; k <= i; k++) {
                for(int l = c; l <= j; l++) {
                    if(pic[k][l] != '.') {
                        if(digit != 100) {
                            valid = false;
                            break;
                        }
                        digit = pic[k][l] - '0';
                    }
                }
                if(!valid) break;
            }
            if(!valid || digit < sum) {
                ec = j;
                break;
            }
            if(digit > sum) continue;
            for(int k = r; k <= i; k++) {
                for(int l = c; l <= j; l++) {
                    ans[k][l] = ch;
                    //cout << ch << endl;
                }
            }
            if(dfs(id + j - c + 1, ch + 1)) return true;
            for(int k = r; k <= i; k++) {
                for(int l = c; l <= j; l++) {
                    ans[k][l] = '.';
                }
            }
        }
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> k && n && k) {
        for(int i = 0; i < n; i++) {
            cin >> pic[i];
        }
        memset(ans, '.', sizeof(ans));
        dfs(0, 'A');
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }    
    return 0;
}