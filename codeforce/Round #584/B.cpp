#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct lamp {
    int ai, bi;
    bool on;
}l[200];    

set<string> ss;
int maxn = 0;

void updateMax(string& s1) {
    int cnt = 0;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] == '1') cnt++; 
    }
    maxn = max(maxn, cnt);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int time = 10;
    for(int i = 0; i < n; i++) {
        cin >> l[i].ai >> l[i].bi;
        l[i].on = s[i] == '1';
        time = min(time, l[i].bi);
    }
    ss.insert(s);
    updateMax(s);
    while (time <= 6e5) {  
        string s1;
        for(int i = 0; i < n; i++) {
            //cout << l[i].bi << " ";
            //cout << "time:" << time << " b[i]" << l[i].bi << " a[i]" << l[i].ai << endl;
            if(l[i].bi <= time && ((time - l[i].bi) % l[i].ai == 0)) {
                l[i].on = !l[i].on;
            }
            s1 += (l[i].on + '0');
        }
        //cout << s1 << endl;
        // if(ss.count(s1)) {
        //     break;
        // }
        //cout << s1 << endl;
        // ss.insert(s1);
        updateMax(s1);
        time++;
    }
    cout << maxn << endl;

    
    
    return 0;
}