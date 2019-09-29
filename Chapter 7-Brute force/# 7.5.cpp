#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define SF(a) scanf("%d", &a)
#define PF(a) printf("%d\n", a)  
#define SFF(a, b) scanf("%d%d", &a, &b)  
#define SFFF(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define IN() freopen("in.txt", "r", stdin)
#define OUT() freopen("out.txt", "w", stdout)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
#define maxn 5
#define maxm 205
#define mod 1000000007
#define INF 10000
using namespace std;
//-------------------------CHC------------------------------//
typedef int state[5];
vector<int> step;
state s;
int n, ans;
 
bool conflict(state sta, int d) {
	FOR(i, 0, 5)
		if (s[i] & (sta[i] >> d))
			return true;
	return false;
}
 
void dfs(int clock, int d, state cur) {
	if ((9 - d) * step[0] + clock + n >= ans) return;	//最优性剪枝
	if (d == 9) { 
		ans = min(ans, clock + n);
		return; 
	}
	FOR(i, 0, step.size()) {
		if (!conflict(cur, step[i])) {
			state newcur;
			FOR(j, 0, 5)
				newcur[j] = s[j] | (cur[j] >> step[i]);
			dfs(clock + step[i], d + 1, newcur);
		}
	}
}
 
int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
	while (SF(n), n) {
		char ch;
		CLEAR(s, 0);
		step.clear();
		FOR(i, 0, 5) {
			getchar();
			FOR(j, 0, n) {
				ch = getchar();
				if (ch == 'X') s[i] |= (1 << j);
			}
		}
		FOR(i, 1, n + 1)	//预处理，避免无用判断
			if (!conflict(s, i)) step.push_back(i);
		ans = INF;
		dfs(0, 0, s);
		PF(ans);
	}
	return 0;
}