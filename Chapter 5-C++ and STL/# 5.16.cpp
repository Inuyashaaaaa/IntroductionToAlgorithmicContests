#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x7fffffff
#define EPS 1e-6
using namespace std;

int now;
int n, m, T, t1, t2, t3, k;
struct Fac {
	int id;
	int useMin;
	int lastTime; //下次什么时间可以用？
	char type;
	Fac(int id, int lastTime, char type = 'R') :id(id), lastTime(lastTime), useMin(0),type(type) {}
	Fac() {}
	bool friend operator < (const Fac& b1, const Fac& b2) {
		// 优先队列 false 表示在前
		if (b1.type == 'R') {
			if (b1.lastTime <= now && b2.lastTime > now) return false;
			if (b1.lastTime > now &&  b2.lastTime <= now) return true;
			return b1.id > b2.id;
		}
		else {
			if (b1.lastTime + t1 <= now && b2.lastTime + t1 > now) return false;
			if (b1.lastTime + t1 > now &&  b2.lastTime + t1 <= now) return true;
			return b1.id > b2.id;
		}
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


//多个病人同时结束手术
bool cmp(Paitent& p1, Paitent& p2) {
	return p1.roomID < p2.roomID;
}

bool cmp2(Paitent& p1, Paitent& p2) {
	return p1.id < p2.id;
}

bool cmp3(Fac& f1, Fac& f2) {
	return f1.id < f2.id;
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
		roomQ.push(Fac(i, -INF));
	}
	for (int i = 1; i <= m; i++) {
		BedQ.push(Fac(i, -INF, 'B'));
	}
	for (int i = 1; i <= k; i++) {
		string name;
		int rt, bt;
		scanf("%s%d%d", name.c_str(), &rt, &bt);
		q.push(Paitent(i, name, rt, bt));
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%d%d%d%d%d%d%d", &n, &m, &T, &t1, &t2, &t3, &k) == 7) {
		T *= 60; //化为分钟
		init();
		now = T;
		int finish = 0;
		int maxn = 0;
		while (finish != k) {
			//抓去做手术
			
			//启动排序
			priority_queue<Fac> ff;
			Fac f;
			while (!roomQ.empty()) {
				f = roomQ.top();
				roomQ.pop();
				ff.push(f);
			}
			roomQ = ff;
			while (roomQ.top().lastTime <= now) {
				if (q.empty())
					break;
				//启动排序
				priority_queue<Fac> ff;
				Fac f;
				while (!roomQ.empty()) {
					f = roomQ.top();
					roomQ.pop();
					ff.push(f);
				}
				roomQ = ff;

				Paitent p = q.front();
				q.pop();
				f = roomQ.top();
				roomQ.pop();

				p.roomBeginMin = now;
				p.roomEndMin = now + p.roomTime;
				p.roomID = f.id;
				vec1.push_back(p);
				f.lastTime = now + t2  + p.roomTime;
				f.useMin += p.roomTime;
				roomQ.push(f);
			}
			//手术结束时间 = 当前时间
			//抓去看进哪个恢复室
			for (Paitent& p : vec1) {
				if (p.roomEndMin + t1 == now) {
					vec2.push_back(p);
				}
			}
			sort(vec2.begin(), vec2.end(), cmp);
			for (Paitent& p : vec2) {
				//启动排序
				priority_queue<Fac> ff;
				Fac f;
				while (!BedQ.empty()) {
					f = BedQ.top();
					BedQ.pop();
					ff.push(f);
				}
				BedQ = ff;
				f = BedQ.top();
				BedQ.pop();
				f.lastTime = now + p.bedTime + t3;
				f.useMin += p.bedTime;
				BedQ.push(f);

				p.bedBeginMin = now;
				p.bedEndMin = now + p.bedTime;
				p.bedID = f.id;
				maxn = max(p.bedEndMin, maxn);
				vec3.push_back(p);
				finish++;
			}
			vec2.clear();
			now++;
		}
		puts(" Patient          Operating Room          Recovery Room");
		puts(" #  Name     Room#  Begin   End      Bed#  Begin    End");
		puts(" ------------------------------------------------------");
		sort(vec3.begin(), vec3.end(), cmp2);
		for (auto& p : vec3) {
			printf("%2d  %-9s %2d  %3d:%02d  %3d:%02d    %3d  %3d:%02d  %3d:%02d\n",
				p.id, p.name.c_str(), p.roomID, p.roomBeginMin / 60, p.roomBeginMin % 60,
				p.roomEndMin / 60, p.roomEndMin % 60, p.bedID, p.bedBeginMin / 60,
				p.bedBeginMin % 60, p.bedEndMin / 60, p.bedEndMin % 60);
		}

		putchar('\n');
		puts("Facility Utilization");
		puts("Type  # Minutes  % Used");
		puts("-------------------------");

		vector<Fac> v1;
		while (!roomQ.empty()) {
			v1.push_back(roomQ.top());
			roomQ.pop();
		}
		sort(v1.begin(), v1.end(), cmp3);
		for (auto &f : v1) {
			printf("Room %2d %7d %7.2lf\n", f.id, f.useMin, k == 0 ? -0.00 : f.useMin == 0 ? 0.00 : (f.useMin *100.0)/ (maxn - T) - EPS);
		}

		v1.clear();
		while (!BedQ.empty()) {
			v1.push_back(BedQ.top());
			BedQ.pop();
		}
		sort(v1.begin(), v1.end(), cmp3);
		for (auto &f : v1) {
			printf("Bed  %2d %7d %7.2lf\n", f.id, f.useMin,k == 0 ? -0.00 : f.useMin == 0 ? 0.00 : (f.useMin *100.0) / (maxn - T) - EPS);
		}
		putchar('\n');
	}

}