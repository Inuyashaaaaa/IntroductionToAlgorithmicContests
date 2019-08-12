#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //LLRL1RL1
    int n;
    cin >> n;
    bool a[20];
    memset(a,0,sizeof(a));
    string s;
    cin >> s;
    for(int i=0;i<n;i++){ 
        if(s[i] == 'L') {
            for(int j=0;j<10;j++){
                if(a[j]==0)
                {
                    a[j]=1;
                    break;
                }
            }
        }else if(s[i] == 'R') {
            for(int j = 9;j>=0;j--){
                if(a[j]==0)
                {
                    a[j]=1;
                    break;
                }
            }
        }else{
            a[s[i]-'0'] = 0;
        }
    }
    for(int i = 0;i<10;i++){
        cout << a[i];
    }


    return 0;
}