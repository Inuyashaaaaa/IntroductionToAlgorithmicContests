#include<list>
#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    list<char> l;
    list<char> temp;
    while(cin>>s) {
        l.clear();
        temp.clear();
        int len = s.length();
        bool isLast = true;
        for(int i = 0;i < len; i++) {
            if(s[i] == '[') {
                isLast = false;
                temp.reverse();
                for(auto& ch:temp){
                    l.push_front(ch);
                }             
                temp.clear(); 
            }
            else if(s[i] == ']') {
                isLast = true;
                temp.reverse();
                for(auto& ch:temp){
                    l.push_front(ch);
                }             
                temp.clear(); 
            }
            else {
                if(isLast)
                l.push_back(s[i]);          
                else
                temp.push_back(s[i]);
            }
        }
        if(!isLast){
            temp.reverse();
                for(auto& ch:temp){
                    l.push_front(ch);
                }     
        }
        for(auto& ch: l) {
            cout << ch;
        }
        cout << endl;
    }  
}