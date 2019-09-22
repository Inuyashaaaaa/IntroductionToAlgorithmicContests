#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[4 + 2][100 + 50];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> anss[4];
    int T;
    cin >> T;
    while(T--) {
        int r, c;
        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < c; i++) {
            // 长度
            for(int k = 1; k <= r; k++) {
                for(int j = 0; j <= r - k; j++) {
                    int ans = 0;
                    for(int z = 0; z < k; z++) {
                        ans += a[j + z][i];
                    }
                    anss[k - 1].push_back(ans);
                    //cout << ans << " ";
                }
                //cout << endl;
            }    
        }
        int maxn = 0;
        int cnt = 0;
        if(r == 1) {
            cout << *anss[0].begin() << endl;
        } 
        if(r == 2) {
            int cnt = 0;
            for(auto& num: anss[0]) {
                maxn += num;
                cnt++;
                if(cnt == 2) 
                break;
            }
            //cout << *anss[1].begin() << endl;
            cout << max(maxn, *anss[1].begin()) << endl;
        }
        if(r == 3) {
            int cnt = 0;
            for(auto& num: anss[0]) {
                maxn += num;
                cnt ++;
                if(cnt == 3) 
                break;
            }
            maxn = max(maxn, *anss[1].begin() + *anss[0].begin());
            cout << max(maxn, *anss[2].begin()) << endl;
        }
        if(r == 4) {
            int cnt = 0;
            for(auto& num: anss[0]) {
                maxn += num;
                cnt ++;
                if(cnt == 4)
                break;
            }
            cnt = 0;
            int temp = 0;
            for(auto& num: anss[0]) {
                temp += num;
                cnt ++;
                if(cnt == 2) 
                break;
            }
            maxn = max(maxn, temp + *anss[1].begin());
            cnt = 0;
            temp = 0;
            for(auto& num: anss[1]) {
                temp += num;
                cnt ++;
                if(cnt == 2)
                break;
            }
            maxn = max(temp, maxn);
            maxn = max(maxn, *anss[2].begin() + *anss[0].begin());
            maxn = max(maxn, *anss[3].begin());
            cout << maxn << endl;
        }
    }
    return 0;
}