//题目看错，有空再做。
//本题目前可以解决没有溢水的问题

#include<bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> Map;
set<int> ss;
map<int, int> mm;

struct rec {
	int x, y, w, h;
	rec(int x, int y, int w, int h) :x(x), y(y), w(w), h(h) {}
	rec() {}
	bool isCover(int x, int y) const {
		if (x >= this->x && x < this->x + w
			&& y >= this->y && y < this->y + h)
			return true;
		return false;
	}
	friend bool operator == (const rec& r1, const rec& r2) {
		return r1.x == r2.x && r1.y == r2.y && r1.w == r2.w && r1.h == r2.h;
	}
	friend bool operator < (const rec& r1, const rec& r2) {
		return r1.w * r1.h == r2.w * r2.h ?
			(r1.x == r2.x ? r1.y < r2.y : r1.x < r2.x)
			: r1.w * r1.h > r2.w * r2.h;
	}
};

set<rec> setVec;

void split(int x, int y) {
    set<rec> temp;
    for(set<rec>::iterator it = setVec.begin(); it != setVec.end();) {
        if(it -> isCover(x, y)) {
            auto t = *it;
            it = setVec.erase(it);
            //横向切割
            int xx = t.x; int yy = t.y;
            int xe = t.x + t.w;
            int ye = t.y + t.h;
            //切上面
            if(xx != x) {
                temp.insert(rec(xx, yy, x - xx, t.h));
            }
            //切下面
            if(x != xx + t.w - 1) {
                temp.insert(rec(x + 1, yy, xe - x - 1, t.h));
            }
            //切左边
            if(yy != y) {
                temp.insert(rec(xx, yy, t.w, y - yy));
            }
            //切右边
            if(y != yy + t.h - 1) {
                temp.insert(rec(xx, y + 1, t . w, ye - y - 1));
            }
            continue;
        }
        it++;
    }
    setVec.insert(temp.begin(), temp.end());
}