#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e3 + 10;


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sz = s.size();
    int _left = 0;
    int ans = 0;
    vector<int> vec;
    for(int i = 0; i < sz; i++) {
        if(s[i] == '(') _left++;
        int _right = 0;
        for(int j = i + 1; j < sz; j++) {
            if(s[j] == ')') _right++;
        }
        int v = min(_left, _right);
        if(ans < v) {
            vec.clear();
            ans = v;
            int left = v;
            int right = v;
            for(int j = 0; j < sz; j++) {
                if(!left) break;
                if(s[j] == '(') {
                    vec.push_back(j + 1);
                    left--;
                }
            }
            for(int j = sz - 1; j >= 0; j--) {
                if(!right) break;
                if(s[j] == ')') {
                    vec.push_back(j + 1);
                    right--;
                }
            }
        }
    }
    if(ans == 0) {
        cout << 0 << endl;
    }
    else {
        sort(vec.begin(), vec.end());
        cout << 1 << endl;

        cout << vec.size() << endl;
        for(int& num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}