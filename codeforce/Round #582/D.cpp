#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define INF 0x7fffffff

unordered_map<int, vector<int>> m;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        int cnt = 0;
        cin >> x;
        while(x) {
            m[x].push_back(cnt);
            x >>= 1;
            cnt++;
        }
        m[0].push_back(cnt);
    }
    int minn = INF;
    for(auto& pair: m) {
        if(pair.second.size() < k)
        continue;
        sort(pair.second.begin(), pair.second.end());
        int ans = 0;
        for(int i = 0; i < k ; i++) {
            ans += pair.second[i];
        }
        minn = min(ans, minn);
    }
    cout << minn << endl;
    return 0;
}