#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int dayu = 0;
        int xiaoyu = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '<') xiaoyu++;
            else dayu++;
        }
        int top = dayu + 2;
        int lianxuDayu = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '>') {
                lianxuDayu++;
            } else {
                break;
            }
        }
        lianxuDayu++;
        int bot = 1;
        int offset = 0;
        queue<int> q;
        q.push(lianxuDayu);
        if(lianxuDayu == bot)
        bot++;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '>') {
                offset++;
            }
            else {
                for(int i = offset - 1; i >= 0; i--) {
                    q.push(bot +i);
                }
                int val = bot + offset;
                if(lianxuDayu == val) {
                    val++;
                }
                bot = val;
                offset = 0;
                q.push(top++);
            }
        }
        if(offset) {
            for(int i = offset - 1; i >= 0; i--) {
                q.push(bot+i);
            }
            int val = bot + offset;
            if(lianxuDayu == val) {
                val++;
            }
            bot = val;
            offset = 0;
        }
        reverse(s.begin(), s.end());
        dayu = 0;
        xiaoyu = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '>') xiaoyu++;
            else dayu++;
        }
        top = dayu + 2;
        lianxuDayu = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '<') {
                lianxuDayu++;
            } else {
                break;
            }
        }
        lianxuDayu++;
        bot = 1;
        offset = 0;
        stack<int> vec;
        vec.push(lianxuDayu);
        if(lianxuDayu == bot)
        bot++;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '<') {
                offset++;
            }
            else {
                for(int i = offset - 1; i >= 0; i--) {
                    vec.push(bot + i);
                }
                int val = bot + offset;
                if(lianxuDayu == val) {
                    val++;
                }
                bot = val;
                offset = 0;
                vec.push(top++);
            }
        }
        if(offset) {
            for(int i = offset - 1; i >= 0; i--) {
                vec.push(bot + i);
            }
            int val = bot + offset;
            if(lianxuDayu == val) {
                val++;
            }
            bot = val;
            offset = 0;
        }
        while(!vec.empty()) {
            cout << vec.top() << " ";
            vec.pop();
        }
        cout << endl;
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        
        cout << endl;

    }
    // system("pause");
}