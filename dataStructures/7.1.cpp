#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;

int n, m, k;    // n, m, k
int w[7];
int a[maxn];
int cnt = 0;
int maxCnt = 0;

const int maxd = 1e6 + 10;
char* s;
char* s1;


void getWeightAndCnt() {
    int weight = 1;
    for(int i = k - 1; i >= 0; i--) {
        w[i] = weight;
        // cout << w[i] << " ";
        weight *= m;
        maxCnt += weight * m;
    }
    // cout << endl;
}

bool hashTable(const char* s) {
    int hashV = 1;
    char s1 = s[0];
    char s2 = s[1];
    char s3 = s[2];
    for(int i = 0; i < k; i++) {
        hashV += w[i] * (s[i] - 'a');
    }
    // cout << hashV << endl;
    if(!a[hashV]) cnt++;
    a[hashV] = true;
    if(cnt == maxCnt) return false;
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m >> k ) {
        s = new char[maxd];
        s1 = new char[maxd];
        cnt = 0;
        maxCnt = 0;

        cin >> s;
        ms(a);
        getWeightAndCnt();
        for(int i = 0; i < k; i++) {
            s1[i] = s[i];
        } 
        hashTable(s1);
        for(int i = k; i < n; i++) {
            s1++;
            s1[k - 1] = s[i];
            // for(int i = 0; i < k; i++) {
            //     cout << s1[i];
            // }
            //cout << endl;
            if(!hashTable(s1)) break;
        }
        delete[] s;
        cout << cnt << endl;
    }

    

    return 0;
}