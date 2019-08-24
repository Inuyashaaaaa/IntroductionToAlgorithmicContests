#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
bool vis[maxn];

struct Circle {
    double x, y, r;
    friend istream& operator >> (istream &in, Circle &c) {
        in >> c.x >> c.y >> c.r;
        return in;
    }
    bool isTopConnect() {
        return y + r >= 1000 ;
    }
    bool isConnect(Circle &c) {
        return hypot(x - c.x, y - c.y) <= r + c.r;
    }
    bool isBottomConnect() {
        return y - r <= 0;
    }
    bool isLeftConnect() {
        return x - r <= 0;
    }
    bool isRightConnect() {
        return 1000 - x - r <= 0;
    }
    double getLeftValue() {
        return y - sqrt(r * r - x * x); 
    }
    double getRightValue() {
        return y - sqrt(r * r - (1000 - x) * (1000 - x));
    }

}c[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        queue<Circle> q;
        for(int i = 0; i < n; i++) {
            if(c[i].isTopConnect()){
                q.push(c[i]);
                vis[i] = true;
            }
        }
        bool flag = false;
        double leftValue = 1000;
        double rightValue = 1000;
        while(!q.empty()) {
            Circle cc = q.front();
            q.pop();
            if(cc.isLeftConnect()) {
                leftValue = min(cc.getLeftValue(), leftValue);
            }
            if(cc.isRightConnect()) {
                rightValue = min(cc.getRightValue(), rightValue);
            }
            if(cc.isBottomConnect()) {
                flag = true;
            }
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    if(cc.isConnect(c[i])) {
                        q.push(c[i]);
                        vis[i] = true;
                    }
                }
            }
        }
        if(flag) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << fixed << setprecision(2) << 0.00 << " " << 
            leftValue << " " << 1000.00 << " " <<
            rightValue << endl;
        }
    }

}