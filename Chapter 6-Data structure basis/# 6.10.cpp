#include<bits/stdc++.h>
using namespace std;

vector<deque<int>> pile;
set<vector<deque<int>>> s;
bool isEmpty[8];
int t = 14;  //已经发完14张牌了
// 0表示总牌堆 1 - 7 表示剩余牌堆

//初始化牌堆
void init(int x) {
	t = 14;
	memset(isEmpty, false, sizeof(isEmpty));
	pile.clear();
	s.clear();
	pile.resize(8);
	pile[0].push_back(x);
	int a;
	for (int i = 2; i <= 52; i++) {
		cin >> a;
		// cout << a << endl;
		pile[0].push_back(a);
	}
	for (int i = 1; i <= 14; i++) {
		int v = pile[0].front();
		pile[0].pop_front();
		pile[(i - 1) % 7 + 1].push_front(v);
	}
	s.insert(pile);
}

bool deal(int pileCnt) {
	//cout << "length:" << pile[pileCnt].size() <<endl;
	//第一种
	int v1 = pile[pileCnt].back(); pile[pileCnt].pop_back();
	int v2 = pile[pileCnt].back(); pile[pileCnt].pop_back();
	int v3 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	if ((v1 + v2 + v3) % 10 == 0) {
		pile[0].push_back(v1);
		pile[0].push_back(v2);
		pile[0].push_back(v3);
		//cout << "v1 : " << v1 << " v2 : " << v2 << " v3 : " << v3 << endl;
		return true;
	}
	pile[pileCnt].push_back(v2);
	pile[pileCnt].push_back(v1);
	pile[pileCnt].push_front(v3);
	//第二种
	v1 = pile[pileCnt].back(); pile[pileCnt].pop_back();
	v2 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	v3 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	if ((v1 + v2 + v3) % 10 == 0) {
		pile[0].push_back(v1);
		pile[0].push_back(v3);
		pile[0].push_back(v2);
		//cout << "v1 : " << v1 << " v2 : " << v2 << " v3 : " << v3 << endl;
		return true;
	}
	pile[pileCnt].push_back(v1);
	pile[pileCnt].push_front(v3);
	pile[pileCnt].push_front(v2);
	//第三种
	v1 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	v2 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	v3 = pile[pileCnt].front(); pile[pileCnt].pop_front();
	if ((v1 + v2 + v3) % 10 == 0) {
		pile[0].push_back(v3);
		pile[0].push_back(v2);
		pile[0].push_back(v1);
		//cout << "v1 : " << v1 << " v2 : " << v2 << " v3 : " << v3 << endl;
		return true;
	}
	pile[pileCnt].push_front(v3);
	pile[pileCnt].push_front(v2);
	pile[pileCnt].push_front(v1);
	return false;
}

int process() {
	int pileCnt = 1; //表示将放置的牌堆
	while (!pile[0].empty()) {
		//cout << "*" << pileCnt << endl;
		if (pileCnt == 8) pileCnt = 1;
		bool flag = true;
		for (int i = 1; i <= 7; i++) {
			if (!isEmpty[i])
				flag = false;
		}
		//for (int i = 1; i <= 7; i ++) {
		//	for (auto& num : pile[i])
		//		cout << num << "<-";
		//	cout << endl;
		//}
		if (flag) return 0; //赢了
		if (pile[pileCnt].empty()) {
			pileCnt++;
			continue;
		}
		int v = pile[0].front();
		pile[0].pop_front();
		pile[pileCnt].push_front(v);
		t++;
		if (s.count(pile)) return 2;
		s.insert(pile);
		//循环处理

		while (pile[pileCnt].size() >= 3 && deal(pileCnt)) {
			if (s.count(pile)) return 2; //表示循环
			s.insert(pile);
			if (pile[pileCnt].size() == 0)
				isEmpty[pileCnt] = true;
		}
		pileCnt++;
	}
	return 1; //表示失败
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int x;
	while (cin >> x) {
		if (x == 0)
			break;
		init(x);
		switch (process())
		{
		case 0:
			cout << "Win : " << t << endl;
			break;
		case 1:
			cout << "Loss: " << t << endl;
			break;
		case 2:
			cout << "Draw: " << t << endl;
			break;
		default:
			cerr << "unexpected value" << endl;
		}
	}
}