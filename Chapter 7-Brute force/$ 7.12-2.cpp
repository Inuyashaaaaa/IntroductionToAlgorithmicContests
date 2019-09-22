#include<bits/stdc++.h>
#define LL long long
using namespace std;

/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

int line[8][7] = {
    { 0,  2,  6, 11, 15, 20, 22}, //A 0
    { 1,  3,  8, 12, 17, 21, 23}, //B 1
    {10,  9,  8,  7,  6,  5,  4}, //C 2
    {19, 18, 17, 16, 15, 14, 13}, //D 3
    {23, 21, 17, 12,  8,  3,  1}, //E 4
    {22, 20, 15, 11,  6,  2,  0}, //F 5
    {13, 14, 15, 16, 17, 18, 19}, //G 6
    { 4,  5,  6,  7,  8,  9, 10}  //H 7
};

int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int a[24];
char ans[1000];

bool end() {
    for(int i = 0; i < 7; i++) {
        if(a[center[i]] != a[center[i + 1]]) return false;
    }
    return true;
}

int diff(int target) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        if(a[center[i]] == target) {
            cnt++;
        }
    }
    return 9 - cnt;
}

int h() {
    return min(min(diff(1), diff(2)), diff(3));
}

void move(int dir) {
    int t = a[line[dir][0]];
    for(int i = 0; i < 6; i++) {
        a[line[dir][i]] = a[line[dir][i + 1]];
    }
    a[line[dir][6]] = t;
}

bool dfs(int d, int maxd) {
    if(end()) {
        for(int i = 0; i < d; i++) {
            cout << ans[i];
        }
        cout << endl;
        return true;
    }
    if(d + h() > maxd) return false;
    for(int i = 0; i < 8; i++) {
        ans[d] = i + 'A';
        move(i);
        if(dfs(d + 1, maxd)) return true;
        move(rev[i]);
    }
    return false;
}


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> a[0] && a[0]) {
        for(int i = 1; i < 24; i++) 
            cin >> a[i];
        if(end()) {
            cout << "No moves needed" << endl;
        } else {
            int maxd;
            for(maxd = 1; ; maxd++) {
                if(dfs(0, maxd)) {
                    break;
                }
            }
        }
        cout << a[6] << endl;
    }
    return 0;
}