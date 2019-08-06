#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<pair<int,int>,int> Map;

int main() {
    int n;
    while(cin >> n && n) {
        Map.clear();
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            // 看有没有搭档了
            pair<int,int> p;
            p.first = b;
            p.second = a;
            bool isExi = Map.count(p);
            if(isExi) {
                int cnt = Map[p];
                if(cnt == 1) {
                    Map.erase(p);
                }
                else {
                    Map[p]--;
                }
            } else {
                if(Map.count(make_pair(a, b))) {
                    Map[make_pair(a,b)] ++;
                } else {
                    Map[make_pair(a, b)] = 1;
                }
            }        
        }
        if(Map.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //system("pause");
    return 0;
}