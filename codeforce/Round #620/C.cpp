#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 1e2 + 10;

bool connect(int left, int right, int _left, int _right) {
    if(right < _left || left > _right) {
        return false;
    }
    return true;
}

struct Info {
    int left, right, time;
}info[maxn];

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n, t;
        cin >> n >> t;
        for(int i = 0; i < n; i++) {
            cin >> info[i].time >> info[i].left >> info[i].right;
        }
        int _left, _right;
        _left = _right = t;
        int _time = 0;
        for(int i = 0; i < n ;i++) {
            _left -= (info[i].time - _time);
            _right += (info[i].time - _time);
            _time = info[i].time;
            if(!connect(_left, _right, info[i].left, info[i].right)) {
                cout << "NO" << endl;
                goto END;
            }
            _left = max(info[i].left, _left);
            _right = min(info[i].right, _right);
        }
        cout <<"YES" << endl;
        END: continue;
    }
    // system("pause");
}