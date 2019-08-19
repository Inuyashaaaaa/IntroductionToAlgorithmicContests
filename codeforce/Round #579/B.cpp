#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const int maxm = 1e2 + 10;

int query[maxn];//看看有几个
vector<int> vec;

int main() {
    int T;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> T;
    while(T--) {
        int n;
        vec.clear();
        memset(query, 0, sizeof(query));
        cin >> n;
        for(int i = 1; i <= 4 * n; i++) {
            int x;
            cin >> x;
            query[x]++;
        }
        bool flag = true;
        for(int i = 1; i <= maxn - 1 ; i++) {
            if(query[i] % 2 != 0) {
                flag = false;
                break;
            }
            for(int j = 0; j < query[i] /2; j++)
            vec.push_back(i);
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        int size = vec.size();
        int area = vec[0] * vec[2 * n - 1];
        for(int i = 1; i < n; i++) {
            if(vec[i] * vec[2 * n - i - 1] != area)
            {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
        
    }
}