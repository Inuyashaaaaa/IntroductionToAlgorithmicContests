#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    string abc = "abc";
    vector<string> ans;

    do{
        string temp;
        for(int i = 0 ; i < n ; i++) temp += abc;
        ans.push_back(temp);
        ans.push_back(string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]));
    }while(next_permutation(abc.begin(), abc.end()));

    for(auto& ss: ans) {
        if(ss.find(s) == string::npos && ss.find(t) == string::npos) {
            cout << "YES" << endl << ss << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}