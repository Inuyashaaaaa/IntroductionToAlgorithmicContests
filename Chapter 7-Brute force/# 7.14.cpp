#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 100 + 5;
int stick[maxn];
int sum, maxc;
bool vis[maxn];

bool dfs(int cur, int end, int left, int pos, int n) {
    if(cur == end) return true;
    for(int i = pos; i < n; i++) {
        if(!vis[i] && stick[i] < left) {
            vis[i] = 1;
            if(dfs(cur, end, left - stick[i], i + 1, n)) return true;
            vis[i] = 0;
            if(left == sum / (end + 1)) return false;
        }
        if(!vis[i] && stick[i] == left) {
            vis[i] = 1;
            if(dfs(cur + 1, end, sum / (end + 1), 0, n)) return true;
            vis[i] = 0;
            return false;
        }
    }
    return false;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if(n == 0) break;
        sum = 0;
        maxc = -1;
        for(int i = 0; i < n; i++) {
            cin >> stick[i];
            if(stick[i] > maxc) maxc = stick[i];
            sum += stick[i];
        }
        sort(stick, stick + n, cmp);
        //cout << stick[0] << endl;
        bool flag = false;
        int i;
        //cout << sum  << " " << maxc << endl;
        for(i = maxc; i < sum; i++) {
            memset(vis, 0, sizeof(vis));
            if(sum % i != 0) continue; //无法整除
            //cout << i << endl;
            if(dfs(0, sum / i - 1, i, 0, n)) { 
                flag = true;
                break;
            }
        }
        cout << (flag ? i : sum) << endl;
    }

    return 0;
}