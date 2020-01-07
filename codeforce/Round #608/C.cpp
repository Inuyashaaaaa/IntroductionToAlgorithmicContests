#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;

struct node {
    int cnt;
    int index;
};

bool cmp(node n1, node n2) {
    return n1.cnt > n2.cnt;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    node no[4];
    for(int i = 0; i < 4;i ++) {
        no[i].index = i;
        no[i].cnt = 0;
    }
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x > a) {
            no[0].cnt++;
        }
        if(x < a) {
            no[1].cnt++;
        }
        if(y > b) {
            no[2].cnt++;
        }
        if(y < b) {
            no[3].cnt++;
        }
    }
    sort(no, no + 4, cmp);
    // for(auto& num: no) {
    //     cout << num.cnt << endl;
    // }
    switch (no[0].index)
    {
    case 0:
        cout << no[0].cnt << endl;
        cout << a + 1 << ' ' << b << endl;
        break;
    case 1:
        cout << no[0].cnt << endl;
        cout << a - 1 << ' ' << b << endl;
        break;
    case 2:
        cout << no[0].cnt << endl;
        cout << a  << ' ' << b + 1 << endl;
    break;
    case 3:
        cout << no[0].cnt << endl;
        cout << a  << ' ' << b - 1 << endl;
    break;  
    default:
        break;
    }

    return 0;
}