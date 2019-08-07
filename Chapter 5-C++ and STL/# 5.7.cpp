#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Task {
	int pos;
	bool index;
	Task(int pos, bool index = false) {
		this->pos = pos;
		this->index = index;
	}
};


int main() {
    // freopen("5-7.in", "r", stdin);
    // freopen("5-7.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		vector<Task> vec;
		int n, pos;
		cin >> n >> pos;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i != pos)
				vec.push_back(Task(x));
			else
				vec.push_back(Task(x, true));
		}
		int time = 0;
		while (1) {
			int x;
			bool index;
			x = vec[0].pos;
			index = vec[0].index;
			vec.erase(vec.begin());
			bool judge = false;
			for (auto& task : vec) {
				if (task.pos > x) {
					judge = true;
					break;
				}
			}
			if (judge) {
				vec.push_back(Task(x, index));
			}
			else {
				if (index) {
					time++;
					break;
				}
				else {
					time++;
				}
			}
		}

		cout << time << endl;
	}
	//system("pause");
	return 0;
}