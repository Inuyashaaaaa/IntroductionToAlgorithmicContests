#include<bits/stdc++.h>
using namespace std;

int in[26];
int out[26];
int p[26];
bool vis[26];

//并查集
void init() {
    for(int i = 0;i < 26; i++) {
        p[i] = i;
    }
}

int find(int a) {
    while(a != p[a]) {
        a = p[a];   
    }
    return a;
}

void merge(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c != d)
    p[d] = c;
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n;
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(vis, false, sizeof(vis));

        cin >> n;
        string s;
        init();
        while(n--) {
            cin >> s;
            int len = s.length();
            int index1 = s[0] - 'a';
            int index2 = s[len - 1] - 'a';
            in[index1]++;
            out[index2]++;
            vis[index1] = true;
            vis[index2] = true;
            merge(index1, index2);
        }
        //连通性
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(vis[i] && i == p[i]) cnt++;
        }
        if(cnt > 1) {
            cout << "The door cannot be opened." << endl;
            continue;
        }
        int beginPos = -1;
        int endPos = -1;
        bool ok = true;
        for(int i = 0; i < 26; i++) {
            if(in[i] == out[i])
            continue;
            if(in[i] == out[i] + 1 && endPos == -1) endPos = i;
            else if(in[i] == out[i] - 1 && beginPos == -1) beginPos = i;
            else ok = false;
        }
        cout << (ok ? "Ordering is possible." : "The door cannot be opened.") << endl;
    }
}