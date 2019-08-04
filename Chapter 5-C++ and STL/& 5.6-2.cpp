#include<iostream>
#include<map>
#include<queue>
using namespace std;

const int maxt = 1010;

int main()
{
    int t, kase = 0;
    while (cin >> t && t) {
        cout << "Scenario #" << ++kase << endl;

        map<int,int> team;
        for(int i = 0; i < t; i++) {
            int n, x;
            cin >> n;
            while(n--) {
                cin >> x;
                team[x] = i;
            }
        }

        queue<int> q, q2[maxt];

        for(;;) {
            char cmd[10];
            int x;
            cin >> cmd;
            if(cmd[0] == 'S')
            break;
            if(cmd[0] == 'E') {
                cin >> x;
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
            if(cmd[0] == 'D') {
                int t = q.front();
                cout << q2[t].front() << endl;
                q2[t].pop();
                if(q2[t].empty()) q.pop();
            }
        }
        cout << endl;
    }
    return 0;
}