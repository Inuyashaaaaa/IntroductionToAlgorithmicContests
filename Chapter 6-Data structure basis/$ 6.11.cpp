#include<bits/stdc++.h>
using namespace std;

const int len = 32;
const int maxn = 1024 + 5;
char s[maxn];
int buf[len][len];
int cnt;

// 2 1
// 3 4
void draw(int& p, int r, int c, int w) {
    char ch = s[p++];
    if(ch == 'p') {
        draw(p, r        , c + w / 2, w / 2);
        draw(p, r        , c        , w / 2);
        draw(p, r + w / 2, c        , w / 2);
        draw(p, r + w / 2, c + w / 2, w / 2);    
    }
    if(ch == 'f') {
        for(int i = r; i < r + w; i++) {
            for(int j = c; j < c + w; j++) {
                if(!buf[i][j]) cnt++;
                buf[i][j] = 1;
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        memset(buf, 0, sizeof(buf));
        cnt = 0;
        cin >> s;
        int p = 0;
        draw(p, 0, 0, len);
        cin >> s;
        p = 0;
        draw(p, 0, 0, len);
        cout << "There are " << cnt << " black pixels." << endl;
    }
}