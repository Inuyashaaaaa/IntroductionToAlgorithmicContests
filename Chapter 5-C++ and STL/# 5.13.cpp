#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

const int MAXN = 10;
#define INF 0x7fffffff


struct task {
	int beginTime;      //开始时间
	int continueTime;   //持续时间
	task() {}
	task(int b, int c) :beginTime(b), continueTime(c) {}
};


unordered_map<int, queue<task>> Map;

struct service {
	int pid;            //员工编号
	int nowTime;        //当前时间
	vector<int> tid;    //工作总类
	int workTimeLeft;   //当前工作剩余时间
	int status;         //当前状态 0 表示可以工作 1表示不能工作
	int lastWorkTime;   //上一次开始工作时间
	service(int nt = 0, int wtl = 0, int st = 0, int lwt = 0) :nowTime(nt), workTimeLeft(wtl), status(st), lastWorkTime(lwt) {}
	friend bool operator < (service& s1, service& s2) {
		if (s1.status == 0 && s2.status == 1) return true;
		if (s1.status == 1 && s2.status == 0) return false;
		if (s1.lastWorkTime < s2.lastWorkTime) return true;
		if (s1.lastWorkTime > s2.lastWorkTime) return false;
		return s1.pid < s2.pid;
	}
};

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n;
    int kase = 0;
    while(cin >> n && n){
        service ser[MAXN];
        for (int i = 0; i < n; i++) {
            int tid, num, t0, t, dt;
            cin >> tid >> num >> t0 >> t >> dt;
            for (int j = 0; j < num; j++) {
                Map[tid].push(task(t0, t));
                t0 += dt;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int k;
            cin >> ser[i].pid >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                ser[i].tid.push_back(x);
                
            }
        }

        //按分钟模拟
        int time = 0;
        while (!Map.empty()) {
            sort(ser, ser + m);
            for (service& s : ser) {
                bool status = s.status;
                if (!status) {
                    for (int i = 0;i < s.tid.size(); i++) {
                            task t;
                        if (Map.count(s.tid[i]))
                            t = Map[s.tid[i]].front();
                        else
                            continue;
                        if (t.beginTime <= time) {
                            s.status = 1;
                            s.lastWorkTime = time;
                            s.workTimeLeft = t.continueTime;
                            Map[s.tid[i]].pop();
                            if (Map[s.tid[i]].empty())
                                Map.erase(s.tid[i]);
                            break;
                        }

                    }
                }
                else {
                    break;
                }
            }
            int minTime = INF;
            for (service& s : ser) {
                minTime = min(minTime, s.workTimeLeft);
            }
            if(minTime == 0) minTime = 1;
            for (service& s : ser) {
                s.nowTime += minTime;
                if (s.status) {
                    s.workTimeLeft -=minTime;
                }
                if (s.workTimeLeft == 0) {
                    s.status = 0;
                }
            }
            time += minTime;
        }
        int maxLeft = 0;
        for (service& s : ser) {
            maxLeft = max(s.workTimeLeft, maxLeft);
        }
        time += maxLeft;
        cout << "Scenario " << ++kase << ": All requests are serviced within " << time << " minutes." << endl;
    }
	
	return 0;
}