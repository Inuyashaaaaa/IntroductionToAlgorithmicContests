#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
const int maxn = 20 + 5;


struct Node {
    // 系数 指数
    double coe;
    int exp;
    Node(double coe, int exp):coe(coe), exp(exp) {}
    Node() {}
};
vector<Node> data[maxn];
string symbol;
map<int, double> map1, map2, map3; //指数 -> 系数 

void add() {
    for(map<int, double>::iterator it = map2.begin();
    it != map2.end(); it++) {
        double coe = it->second;
        int exp = it->first;
        if(map1.count(exp)) {
            map1[exp] += it->second;
        } else {
            map1[exp] = it->second;
        }
    }
}

void div() {
    for(map<int, double>::iterator it = map2.begin();
    it != map2.end(); it++) {
        double coe = it->second;
        int exp = it->first;
        if(map1.count(exp)) {
            map1[exp] -= it->second;
        } else {
            map1[exp] = -it->second;
        }
    }
}

void mul() {
   map3.clear();
   for(map<int, double>::iterator it1 = map1.begin();
   it1 != map1.end(); it1++) {
       for(map<int, double>::iterator it2 = map2.begin();
       it2 != map2.end(); it2++) {
           double coe1 = it1->second;
           double coe2 = it2->second;
           double coe3 = coe1 * coe2;
           int exp1 = it1->first;
           int exp2 = it2->first;
           int exp3 = exp1 + exp2;
           if(map3.count(exp3)) {
               map3[exp3] += coe3;
           } else {
               map3[exp3] = coe3;
           }
       }
   }
   map1 = map3;
}

void show() {
    map<int, double>::reverse_iterator it = map1.rbegin();
    //获取第一个不是0的
    while(it -> second == 0) {
        it++;
        if(it == map1.rend()) {
            cout << 0;
            return;
        }
    }
    if(it -> second == -1) {
        if(it -> first == 0) cout << "-1";
        else cout << "-";
    }
    else if(it -> second != 1) {
        cout << it->second;
    }
    else if(it -> first == 0) {
        cout << 1;
    }
    if(it -> first == 1) cout << "x";
    else if(it -> first > 0) 
    cout << "x^" << it->first;

    for(it++; it != map1.rend(); it++) {
        if(it -> second == 0) continue;
        if(it -> second > 0) cout << "+";
        if(it -> second == -1) {
            if(it -> first == 0) cout << "-1";
            else cout << "-";
        }
        else if(it -> second != 1) {
            cout << it -> second;
        }
        else if(it -> first == 0) {
            cout << 1;
        }
        if(it -> first == 1) {
            cout << "x";
        } 
        else if(it -> first > 1) {
            cout << "x^" << it->first;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++) {
            double coe;
            int exp;
            cin >> coe >> exp;
            data[i].push_back(Node(coe, exp));
        }
    }
    cin >> symbol;
    int sz = data[1].size();
    for(int i = 0; i < sz; i++) {
        map1[data[1][i].exp] = data[1][i].coe;
    }
    for(int i = 2; i <= k; i++) {
        sz = data[i].size();
        map2.clear();
        for(int j = 0; j < sz; j++) {
            map2[data[i][j].exp] = data[i][j].coe;
        }
        if(symbol[i - 2] == '+') add();
        if(symbol[i - 2] == '-') div();
        if(symbol[i - 2] == '*') mul();
    }
    show();
    return 0;
}
