#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 2e5;

struct Student {
    int id;
    double score[3];
}s[maxn];

int rank1[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int kase = 0;
    while(cin >> n && n) {
        cout << "Case " << ++kase << ": "; 
        if(kase == 28)  int w = 1;
        for(int i = 1; i <= n; i++) {
            s[i].id = i;
            cin >> s[i].score[0] >> s[i].score[1]
            >> s[i].score[2];
        }
        for(int i = 1; i <= n; i++) {
            cin >> rank1[i];
        }
        double tot = s[rank1[1]].score[0] + s[rank1[1]].score[1] + s[rank1[1]].score[2];
        int id = s[rank1[1]].id;
        bool flag = true;
        for(int i = 2; i <= n; i++) {
            //在后面 则可以相等
            // 000 001 010 011 100 101 110 111
            double ans[8];
            for(int j = 0; j < 8; j++) {
                double t = 0;
                for(int k = 0; k < 3; k++)
                if((j >> k) & 1) t += s[rank1[i]].score[k];
                ans[j] = t;
            }
            double e = ans[7]; //tot
            sort(ans, ans + 8); //从小到大尝试删掉
            //id大可以相同
            bool isok = false;
            for(int j = 0; j < 8; j++) {
                if((fabs(e - ans[j] - tot) > 1e-6 && (e - ans[j] < tot)) 
                || (fabs(e - ans[j] - tot) < 1e-6 && s[rank1[i]].id > id)){
                    tot = e - ans[j];
                    id = s[rank1[i]].id;
                    isok = true;
                    break;
                }
            }
            if(!isok) {
                flag = false;
                break;
            }
        }
        if(!flag) cout << "No solution" << endl;
        else cout << fixed << setprecision(2) << tot << endl;
    }
    return 0;
}