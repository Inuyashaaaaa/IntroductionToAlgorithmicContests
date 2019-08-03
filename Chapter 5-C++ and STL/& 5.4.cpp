#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string,string> cnt;
vector<string> word;

string repr(const string& s) {
    string ans = s;
    for(int i = 0; i < ans.length() ; i++) {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 0;
    string s;
    while(cin >> s) {
        if(s[0] == '#')
        break;
        string r = repr(s);
        if(cnt.find(r) == cnt.end())
        cnt[r] = s;
        else
        cnt[r] = "#";
    }
    for(map<string,string>::iterator iter = cnt.begin(); iter!=cnt.end() ; iter++){
        if( iter->second != "#")
        word.push_back(iter->second);
    }
    sort(word.begin(),word.end());
    for(auto& s:word){
        cout << s << endl;
    }
    // system("pause");
    return 0;
}

//for loops are not allowed in C++ 98 mode 
//下载最新dev
