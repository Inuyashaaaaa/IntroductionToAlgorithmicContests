#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int way1 = 0;
    int way2 = 0;
    int aCnt = 0;
    int bCnt = 0;
    vector<int> way11;
    vector<int> way22;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' && t[i] == 'b') {
            way1++;
            way11.push_back(i + 1);
        } 
        if(s[i] == 'b' && t[i] == 'a') {
            way22.push_back(i + 1);
            way2++;
        }
        if(s[i] == 'a') aCnt++;
        if(s[i] == 'b') bCnt++;
        if(t[i] == 'a') aCnt++;
        if(t[i] == 'b') bCnt++; 
    }
    if(aCnt % 2 != 0 || bCnt % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    if(way1 % 2 == 0 && way2 % 2 == 0) {
        cout << way1 / 2 + way2 / 2 << endl;
        for(int i = 0; i < int(way11.size()) - 1; i+=2) {
            cout << way11[i] << " " << way11[i + 1] << endl;;
        }
        for(int i = 0; i < int(way22.size()) - 1; i+=2) {
            cout << way22[i] << " " << way22[i + 1] << endl;
        }
        return 0;
    }
    cout << way1 / 2 + way2 / 2 + 2 << endl;
    for(int i = 0; i < int(way11.size())- 1; i+=2) {
            cout << way11[i] << " " << way11[i + 1] << endl;;
    }
    for(int i = 0; i < int(way22.size()) - 1; i+=2) {
            cout << way22[i] << " " << way22[i + 1] << endl;;
    }
    cout << way11[way11.size() - 1] << " " << way11[way11.size() - 1] << endl;
    cout << way11[way11.size() - 1] << " " << way22[way22.size() - 1] << endl;
    return 0;
}