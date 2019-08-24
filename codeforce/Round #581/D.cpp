#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

char s1[maxn];
char s2[maxn * 2];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> s1;
    memset(s2, '0', sizeof(s2));
    int size = strlen(s1);
    int cnt = 0;
    for(int i = 0; i < size; i++) {
        if(s1[i] == '1') {
            cnt ++;
        }else {
            for(int j = 0;j < cnt && i + j < size; j++) {
                s2[i + j] = s1[i + j];
            }
            cnt = 0;
        }
    }
    cnt = 0;
    for(int i = 0; i < size; i++) {
        if(s1[i] == '0') {
            cnt ++;
        }else {
            for(int j = 1;j <= cnt && i - cnt - j >= 0; j++) {
                s2[i - cnt - j] = s1[i - cnt - j];
            }
            cnt = 0;
        }
    }
    if(cnt) {
        for(int j = 1;j <= 1 && size - cnt - j >= 0; j++) {
                s2[size - cnt - j] = s1[size - cnt - j];
            }
    }
    for(int i = size - 1; i < size;i ++) {
        if(s1[i] == '1')
        s2[i] = '0';
        else
        break;
    }
    for(int i = 0; i < size; i++) {
        cout << s2[i];
    }
}