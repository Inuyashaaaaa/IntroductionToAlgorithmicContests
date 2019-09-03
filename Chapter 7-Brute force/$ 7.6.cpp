#include<bits/stdc++.h>
#define LL long long
#define INF 0x7fffffff
using namespace std;

unordered_map<char, set<char>> m;
char B[10];
set<char> vis;
vector<char> ele;
bool viS[10];
int k = INF;
int n;

void dfs(int cur, char* A, int NowK) {
    if(cur == n && NowK < k) {
        memcpy(B, A, 10);
        k = NowK;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!viS[i]) {
            A[cur] = ele[i];
            for(int j = 0; j < cur; j++) {
                if(m[ele[i]].count(A[j])) {
                    NowK = max(cur - j, NowK);
                }
            }
            if(NowK >= k) return;
            viS[i] = 1;
            dfs(cur + 1, A, NowK);
            viS[i] = 0;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s && s != "#") {
        k = INF;
        m.clear();
        vis.clear();
        ele.clear();
        memset(viS, 0, sizeof(viS));
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ':' || s[i] == ';') s[i] = ' ';
        }
        stringstream ss(s);
        char ch;
        while(ss >> ch) {
            vis.insert(ch);
            string temp;
            ss >> temp;
            for(int i = 0; i < temp.size(); i++) {
                m[ch].insert(temp[i]);
                m[temp[i]].insert(ch);
                vis.insert(temp[i]);
            }
        }
        n = vis.size();
        for(auto& ch: vis) {
            ele.push_back(ch);
        }
        char A[10];
        dfs(0, A, 0);
        for(int i = 0; i < n; i++) {
            cout << B[i] << " ";
        }
        cout << "-> " << k ;
        cout << endl;
    }

    return 0;
}