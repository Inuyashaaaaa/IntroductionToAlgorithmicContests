#include<queue>
#include<iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }
        cout << "Discarded cards:";
        int first = 0;
        while(q.size() != 1) {
            if(first++)
            cout << ",";
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
        q.pop();
    }
    return 0;
}