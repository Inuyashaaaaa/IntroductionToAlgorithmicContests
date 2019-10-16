//2019/10/13 23.58
/*
算法与数据结构实验题 5.17 人潮最多时段
★实验任务 有一群客人参加宴会，他们都在固定时间点到场和离场，现在想统计宴会最多人是在什么时间段，有多少人。
宴会时间从 1 开始，最后一个人离开时宴会结束。假设人员到场与离开是瞬间发生，不需要额外时间。
★数据输入
一个数N表示人员总数。
从第二行到N+1行，每一行两个数，第一个数是该人到场时间，第二个数是该人离场时间。（时间都在int范围里）
50%数据 1<= <=50000
100%数据 1<= <=100000
★数据输出
第一行输出三个数，前两个数代表宴会最多人时间段中间用‘-’链接，第三个数为最多多少人。第三个数与前面两个数有空格。
如果有多个时间段人数一样输出开始时间最靠前的时间段，时间段必须为该人数保持的最大时间段，即不能为该时间段的子时间段。
*/



#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 5;
int a[2 * maxn];
int b[2 * maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int _left, _right;
        _left = maxn;
        _right = 0;
        for(int i = 0; i < n; i++) {
            int c, d;
            cin >> c >> d;
            if(c < _left) _left = c;
            if(d > _right) _right = d; 
            a[c]++;
            b[d]++;
        }
        int maxc = -1;
        int cnt = 0; //记录person数量
        bool judge = false;
        for(int i = 1; i <= maxn; i++) {
            int p = a[i] - b[i];
            cnt += p;
            if(cnt > maxc)  {
                _left = i;
                judge = true;
            }
            if(p < 0 && judge) {
                _right = i;
                judge = false;
            }
            maxc = max(maxc, cnt);
            //cout << _left << " " << _right << " " << maxc << endl;
        }
        cout << _left << "-" << _right << " " << maxc << endl;
    }
    return 0;
}