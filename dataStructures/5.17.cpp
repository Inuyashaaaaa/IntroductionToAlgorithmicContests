//2019/10/7 21:03
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
int a1[4 * maxn];
int b1[4 * maxn];
int c1[4 * maxn];
int a2[4 * maxn];
int b2[4 * maxn];

/*离散化*/
void discretization(int* a, int& n) {
	sort(a, a + n);
	n = unique(a, a + n) - a;
}

int getId(int* a, int n, int k) {
	return lower_bound(a, a + n, k) - a;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(a2, 0, sizeof(a2));
    memset(b2, 0, sizeof(b2));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a1[i] >> b1[i];
        c1[i * 2] = a1[i];
        c1[i * 2 + 1] = b1[i];
    }
    n *= 2;
    discretization(c1, n);
    for(int i = 0; i < n; i++) {
        int id = getId(c1, n, a1[i]);
        a2[id]++;
        id = getId(c1, n, b1[i]);
        b2[id]++;
    }
    LL cnt = 0;
    LL maxc = -1;
    int _left = c1[0];
    int _right = c1[n - 1];
    bool judge = false;
    for(int i = 0; i < 2 * n; i++) {
        int p = a2[i] - b2[i];
        cnt += p;
        if(cnt > maxc)  {
            _left = c1[i];
            judge = true;
        }
        if(p < 0 && judge) {
            _right = c1[i];
            judge = false;
        }
        maxc = max(maxc, cnt);
        //cout << _left << " " << _right << " " << maxc << endl;
    }
    cout << _left << "-" << _right << " " << maxc << endl;



    return 0;
}