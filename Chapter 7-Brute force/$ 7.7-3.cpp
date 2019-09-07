#include<bits/stdc++.h>
#define LL long long
using namespace std;

double maxWid;
double nowWid;
int num;

struct Node{
    double left, right;
    double w;
}n[1<<6];

bool vis[1<<6];

void dfs(int cur) {
    if(cur == num - 1) {
        double width = n[2 * cur].left + n[2 * cur].right;
        if(width < maxWid && width > nowWid) {
            nowWid = width;
        } 
        return;
    }
    for(int i = 0; i < cur + num; i++) {
        for(int j = 0; j < cur + num; j++) {
            if(i == j) continue;
            if(!vis[i] && !vis[j]) {
                vis[i] = vis[j] = 1;
                n[cur + num].w = n[i].w + n[j].w;
                double leftV = n[j].w / n[cur + num].w;
                double rightV = n[i].w / n[cur + num].w;
                n[cur + num].left = max(n[i].left + leftV,
                n[j].left - rightV);
                n[cur + num].right = max(n[i].right - leftV,
                n[j].right + rightV);
                dfs(cur + 1);
                vis[i] = vis[j] = 0;
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        memset(vis, 0, sizeof(vis));
        memset(n, 0, sizeof(n));
        cin >> maxWid >> num;
        nowWid = 0;
        for(int i = 0; i < num; i++) 
        cin >> n[i].w;
        dfs(0);
        if(nowWid == 0 && num != 1) {
            cout << "-1" << endl;
        } else {
            cout << fixed << setprecision(15) << nowWid << endl;
        }
    }
    return 0;
}