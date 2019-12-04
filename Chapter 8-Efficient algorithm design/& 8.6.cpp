#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e4 + 10;

vector<pair<int, int>> vec;
int a[maxn];
int p[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        vec.clear();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            p[a[i]] = i;
        }
        for(int i = 1; i <= n; i++) {
            if(i == a[i]) continue;
            int pos = p[i];
            //step 1
            int mid = (i + pos) / 2;
            int len = mid - i + 1;
            if((i + pos) % 2 == 0) len--; 
            vec.push_back(make_pair(pos - 2 * len + 1,pos));
            if(pos - 2 * len + 1 - pos != 1) {
                for(int j = pos - 2 * len + 1; j <= mid; j++) {
                    swap(a[j], a[j + len]);
                    p[a[j]] = j;
                    p[a[j + len]] = j + len;
                }
            } else {
                swap(a[pos - 2 * len + 1], a[pos]);
                p[a[pos - 2 * len + 1]] = pos - 2 * len + 1;
                p[a[pos]] = pos;
            }
            if(i == a[i]) continue;
            len = p[i] - i;
            vec.push_back(make_pair(i, i + 2 * len - 1));
            for(int j = i; j < i + len; j++) {
                swap(a[j], a[j + len]);
                p[a[j]] = j;
                p[a[j + len]] = j + len;
            }
        }
        cout << vec.size() << endl;
        for(auto& pair: vec) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}