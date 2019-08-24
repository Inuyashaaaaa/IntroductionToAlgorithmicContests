#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    cin >> s;
    
    int len = s.size();
    int train = (len + 1) /2 - 1;
    if(len % 2 == 1)
    for(int i = 1; i < len; i++) {
        if(s[i] == '1') {
            train ++;
            break;
        }
    }
    else
    train++;
    cout << train << endl;

    return 0;
}