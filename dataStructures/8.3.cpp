#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e4 + 10;
int n, m;

struct Student {
    int id, score;
    Student(int id, int score):id(id), score(score){}
    Student(){}
    friend bool operator < (const Student& s1, const Student& s2) {
        return s1.score == s2.score ? s1.id > s2.id : s1.score > s2.score;
    }
};


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    priority_queue<Student> pq;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pq.push(Student(i, x));
    }
    cin >> m;
    //cout << m << endl;
    for(int i = 1; i <= m; i++) {
        cin >> x;
        cout << x << endl;
        Student s = pq.top();
        pq.pop();
        s.score += x;
        pq.push(s);
    }
    cout << pq.top().id << " " << pq.top().score << endl;
    return 0;
}