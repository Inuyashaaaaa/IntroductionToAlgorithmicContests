#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL long long
const int maxn = 100 + 10;
struct Info {
    string s;
    string reverseS;
    bool flag;
    int use;
    Info() {
        s.resize(120);
        reverseS.resize(120);
        flag = false;
        use = 0;
    }
}info[maxn];

bool cmp(Info i1, Info i2) {
    return i1.use < i2.use;
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> info[i].s;
        info[i].reverseS = info[i].s;
        reverse(info[i].reverseS.begin(), info[i].reverseS.end());
    }
    int cnt = 0;
    for(int i = 0; i < a; i++) {
        if(info[i].reverseS == info[i].s) {
            info[i].flag = true;
        }
    }
    for(int i = 0; i < a; i++) {
        if(info[i].use) continue;
        for(int j = 0; j < a; j++) {
            if(info[j].use) continue;
            if(i == j) continue;
            if(info[i].reverseS == info[j].s) {
                cnt++;
                info[i].use = cnt;
                info[j].use = -cnt;
            }
        }
    }
    sort(info, info + a, cmp);
    bool ok = false;
    string ans;
    for(int i = 0; i < a; i++) {
        if(info[i].use) {
            ans += info[i].s;
        }
        if(!info[i].use && info[i].flag == true && !ok) {
            ok = true;
            ans += info[i].s;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    // system("pause"); 
    return 0;
}