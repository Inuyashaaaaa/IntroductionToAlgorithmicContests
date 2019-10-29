#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e4 + 40;

vector<pair<int, double>> G[maxn];
int a[maxn];
bool vis[maxn];
vector<double> vec;

bool cmp(double a,double b)
{
    return a>b;
}

void dfs(int pos, double num) {
    //cout << num << endl;
    int size = G[pos].size();
    vis[pos] = true;
    bool isEnd = true;
    for(int i = 0; i < size; i++) {
        if(vis[G[pos][i].first]) continue;
        //cout << "*" << G[pos][i].second << endl;
        dfs(G[pos][i].first, num * G[pos][i].second);
        isEnd = false;
    }
    vis[pos] = false;
    if(isEnd) {
        //cout << num << endl;
        vec.push_back(num);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(G, 0, sizeof(G));
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        double c;
        cin >> a >> b >> c;
        //cout << a << " " << b << " " << c << endl;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    sort(vec.begin(),vec.end(),cmp);
    double ans = 0;
    for(int i = 0; i < vec.size(); i++) {
        ans += vec[i] * a[i];
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}