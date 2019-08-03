#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<set>
#include<cctype>
using namespace std;

set<string> dict;

int main() {
    ios::sync_with_stdio(false);
    string s, buf;
    while(cin >> s) {
        for(int i = 0; i < s.length() ; i++){
            if(isalpha(s[i])) 
            s[i] = tolower(s[i]);
            else 
            s[i] = ' ';
        }      
        stringstream ss(s);
        while(ss >> buf) dict.insert(buf);
    }
    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;
    // system("pause");
    return 0;
}