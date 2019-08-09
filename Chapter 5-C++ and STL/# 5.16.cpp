
//真的不知道哪里错了 Udebug过了 自己造的数据和AC的代码全都一样 网上的测试数据也都和AC的一样 不管了

#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct Fac {
	int id;
	int useMin;
	int lastTime; //下次什么时间可以用？
	Fac(int id, int lastTime) :id(id), lastTime(lastTime), useMin(0) {}
	Fac() {}
	bool friend operator < (const Fac& b1, const Fac& b2) {
		// 优先队列 false 表示在前
		if (b1.lastTime < b2.lastTime) return false;
		if (b1.lastTime > b2.lastTime) return true;
		return b1.id > b2.id;
	}
};

struct Paitent {
	int id;
	int roomID;
	int roomBeginMin;
	int roomEndMin;
	int roomTime;
	int bedID;
	int bedBeginMin;
	int bedEndMin;
	int bedTime;
	string name;
	Paitent(int id, string name, int rt, int bt) :id(id),
		name(name), roomTime(rt), bedTime(bt) {}
	Paitent() {}
};

priority_queue<Fac> roomQ;      //记录房间号
// 注意恢复室一定可以进
priority_queue<Fac> BedQ;      //记录床位
queue<Paitent> q;
vector<Paitent> vec1;          //等待手术结束
vector<Paitent> vec2;          //手术刚结束等待进入恢复室
vector<Paitent> vec3;          //做完手术了
int n, m, T, t1, t2, t3, k;

//多个病人同时结束手术
bool cmp(Paitent& p1, Paitent& p2) {
	return p1.roomID < p2.roomID;
}

//初始化
void init() {
	vec1.clear();
	while (!roomQ.empty())
		roomQ.pop();
	while (!BedQ.empty())
		BedQ.pop();
	vec3.clear();
	for (int i = 1; i <= n; i++) {
		roomQ.push(Fac(i, T));
	}
	for (int i = 1; i <= m; i++) {
		BedQ.push(Fac(i, T));
	}
	for (int i = 1; i <= k; i++) {
		string name;
		int rt, bt;
		scanf("%s%d%d", name.c_str(), &rt, &bt);
		q.push(Paitent(i, name, rt, bt));
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%d%d%d%d%d%d", &n, &m, &T, &t1, &t2, &t3, &k) == 7) {
		T *= 60; //化为分钟
		init();
		int now = T;
		int finish = 0;
		int maxn = 0;
		while (finish != k) {
			//抓去做手术
			while (roomQ.top().lastTime <= now) {
				if (q.empty())
					break;

				Paitent p = q.front();
				q.pop();
				Fac f = roomQ.top();
				roomQ.pop();

				p.roomBeginMin = now;
				p.roomEndMin = now + p.roomTime;
				p.roomID = f.id;
				vec1.push_back(p);
				f.lastTime += p.roomTime + t2;
				f.useMin += p.roomTime;
				roomQ.push(f);
			}
			//手术结束时间 = 当前时间
			//抓去看进哪个恢复室
			for (Paitent& p : vec1) {
				if (p.roomEndMin == now) {
					vec2.push_back(p);
				}
			}
			sort(vec2.begin(), vec2.end(), cmp);
			for (Paitent& p : vec2) {
				Fac f = BedQ.top();
				BedQ.pop();
				f.lastTime += p.bedTime + t1 + t3;
				f.useMin += p.bedTime;
				BedQ.push(f);

				p.bedBeginMin = now + t1;
				p.bedEndMin = now + t1 + p.bedTime;
				p.bedID = f.id;
				maxn = max(p.bedEndMin, maxn);
				vec3.push_back(p);
				finish++;
			}
			vec2.clear();
			now++;
		}
		printf("%2d:%2d\n", maxn / 60, maxn % 60);
	}

}