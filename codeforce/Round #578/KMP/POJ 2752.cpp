#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 4e5 + 50;
char s[maxn];
int prefix[maxn];

void print(int index){
    if(index){
        print(prefix[index]);
        cout << index << " "; 
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> (s + 1)) {
        int k = 0;
        int len = strlen(s + 1);
        for(int i = 2; i <= len; i++) {
            while(s[i] != s[k + 1] && k) k = prefix[k];
            if(s[i] == s[k+1]) {
                k ++;
                prefix[i] = k;
            }else 
                prefix[i] = 0;
        }
        print(len);       
        cout << endl;
    }
    return 0;
}