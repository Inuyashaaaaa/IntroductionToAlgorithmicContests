#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1000 + 5;

int a[maxn];
map<int, vector<int>> m;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
        m[x].push_back(i + 1);
    }
    LL ans = 0;
    int cnt = 0;
    vector<int> anss;
    for(int i = maxn; i > 0; i--) {
        if(a[i]) {
            while(!m[i].empty()) {
                anss.push_back(m[i].back());
                m[i].pop_back();
            }
        }
        
        while(a[i]) {
            ans += (i * cnt++ + 1); 
            a[i]--;
        }   
    }
    cout << ans << endl;
    for(auto& num: anss) {
        cout << num << " ";
    }
    return 0;
}