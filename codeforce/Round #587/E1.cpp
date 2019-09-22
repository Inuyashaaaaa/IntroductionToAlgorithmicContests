#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
string s[maxn];

void init() {
    a[0] = 0;
    s[0] = ""; 
    for(int i = 1; i < maxn; i++) {
        //cout << "ok" << endl;
        a[i] = a[i - 1];
        int cnt = 0;
        int temp = i;
        while(temp) {
            temp /= 10;
            cnt ++;
        } 
        a[i] += cnt;     
    }
}

char getV(int p) {
    int cnt = 0;
    int i;
    for(i = 1; i < maxn; i++) {
        int v = 0;
        int temp = i;
        while(temp) {
            temp /= 10;
            v++;
        }
        if(p - v < 0) {
            break;
        }
        p -= v;
        
    } 
    i--;
    cout << i << endl;
    cout << p <<endl;
    vector<int> ans;
    while(i) {
        ans.push_back(i % 10);
        i /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans[p] + '0';
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    // for(int i = 1; i <= 13; i++) {
    //     cout << a[i] << endl;
    // }
    int p;
    int T;
    cin >> T;
    while(T--) {
        cin >> p;
        int cnt = 1;

        while(p - a[cnt] > 0) {
            //cout << "ok" << endl;  
            p -= a[cnt];
            cnt++;
        }
        cout << getV(p) << endl;
        //cout << endl;
    }

    return 0;
}