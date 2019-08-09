#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

map<string,string> oldMap;
map<string,string> newMap;

int main() {
    int T;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> T;
    
    cin.get();
    for(int i = 0; i < T; i++) {
        oldMap.clear();
        newMap.clear();
        string s;
        getline(cin, s);
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == '{' || s[i] == ',' || s[i] == ':' || s[i] == '}') 
            s[i] = ' ';
        }
        stringstream ss1(s);
        string s1, s2;
        while(ss1 >> s1 >> s2) {
            oldMap[s1] = s2;
        }
        getline(cin, s);
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == '{' || s[i] == ',' || s[i] == ':' || s[i] == '}') 
            s[i] = ' ';
        }
        stringstream ss2(s);
        while(ss2 >> s1 >> s2) {
            newMap[s1] = s2;
        }
        bool flag = false;
        vector<string> add;
        vector<string> del;
        vector<string> cha;
        //ADD + CHA
        for(auto& pair: newMap) {
            if(!oldMap.count(pair.first))
            add.push_back(pair.first);
            else {
                // cout << "> " << pair.second << endl;
                // cout << "> " << oldMap[pair.first] << endl;
                // cout << "> " << (pair.second == oldMap[pair.first]) << endl;
                // bool judge = pair.second == oldMap[pair.first];
                // cout << "> " << judge << endl;
                if(pair.second != oldMap[pair.first])
                {
                    // cout << "*" << endl;
                    cha.push_back(pair.first);
                }
            }
            
        }
        //DEL
        for(auto& pair: oldMap) {
            if(!newMap.count(pair.first))
            del.push_back(pair.first);
        }

        //ADD
        if(add.size()) {
            flag = true;
            bool first = false;
            cout << "+" ;
            for(auto& s: add) {
                if(first)
                cout << "," ;
                cout << s;
                first = true;
            }
            cout << endl;
        }

        //DEL
        if(del.size()) {
            flag = true;
            bool first = false;
            cout << "-" ;
            for(auto& s: del) {
                if(first)
                cout << "," ;
                cout << s;
                first = true;
            }
            cout << endl;
        }

        //CHA
        if(cha.size()) {
            flag = true;
            bool first = false;
            cout << "*" ;
            for(auto& s: cha) {
                if(first)
                cout << "," ;
                cout << s;
                first = true;
            }
            cout << endl;
        }

        if(!flag)
            cout << "No changes" << endl;
        cout << endl;
    }
    return 0;
}

