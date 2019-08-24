#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string pic[maxn];
int n;

void dfs(int r, int c) {
    cout << pic[r][c] << "(";
    if(r + 1 < n && pic[r + 1][c] == '|') {
        int i = c;
        while(i - 1 >=0 && pic[r + 2][i - 1] == '-') i--;
        while(pic[r + 2][i] == '-' && pic[r + 3][i] != '\0') {
            if(!isspace(pic[r + 3][i])) {
                dfs(r + 3, i);
            }
            i++;
        }
    }
    cout << ")";
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    cin.get();
    while(T--) {
        n = 0;
        while(getline(cin, pic[n])) {
            if(pic[n] == "#")
            break;
            n++;
        }
        cout << "(";
        int len = pic[0].size();
        for(int i = 0; i < len; i++) {
            if(!isspace(pic[0][i]) && pic[0][i] != '#')
            dfs(0, i);
        }
        cout << ")" << endl;
    }
}