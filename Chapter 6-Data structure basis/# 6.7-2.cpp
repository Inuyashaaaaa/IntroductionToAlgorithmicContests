#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int token[maxn];
struct perix {
    unordered_map<int, int> in;
    unordered_map<int, int> out;
};

int main() {
    int n;
    int kase = 0;
    while(cin >> n && n) {
        for(int i = 1; i <= n; i++) 
            cin >> token[i];      
        int q;
        cin >> q;
        perix p[maxn];
        for(int i = 0; i < q; i++) {
            int x;
            while(cin >> x && x) {
                if(x < 0) 
                    if(p[i].in.count(-x)) p[i].in[-x] ++;               
                    else p[i].in[-x] = 1;             
                if(x > 0) 
                    if(p[i].out.count(x)) p[i].out[x] ++;                   
                    else p[i].out[x] = 1;   
            }                           
        }
        int trans;
        cin >> trans;
        int cnt = 0;
        for(int i = 0; i < q; i++) {
            bool flag = true;
            for(auto& pair:p[i].in) 
                if(token[pair.first] < pair.second) {
                    flag = false;
                    break;
                }
            if(!flag) continue;
            for(auto& pair:p[i].in) token[pair.first] -= pair.second;
            for(auto& pair:p[i].out) token[pair.first] += pair.second;
            i = -1;
            if(++cnt >= trans)
            break;
        }
        if(cnt >= trans) cout << "Case " << ++ kase << 
        ": still live after " << trans << " transitions\n";
        else cout << "Case " << ++ kase << 
        ": dead after " << cnt << " transitions\n";
        cout << "Places with tokens:";
        for(int i = 1; i <= n; ++i) if(token[i]) cout << " " << i <<
        " (" << token[i] << ")";
        cout << endl << endl;
    }
    return 0;
}