#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 100 + 5;

struct item {
    double coe; //系数
    double exp; //指数
    item(double coe, double exp):coe(coe), exp(exp) {}
    item(){}
    friend bool operator < (const item& i1, const item& i2) {
        return i1.exp > i2.exp;
    }
};
vector<item> vec[maxn];
// 0 用来存原始的

int search(int k, double exp) {
    for(int i = 0; i < vec[k].size(); i++) {
        if(vec[k][i].exp == exp) {
            return i;
        }
    }
    return -1;
}

//第一个参数是被加数
void addOrSub(int z, int k, bool isAdd) {
    //遍历k数据段的所有
    for(int i = 0; i < vec[k].size(); i++) {
        int w = search(0, vec[k][i].exp);
        if(w == -1) {
            if(!isAdd)
                vec[k][i].coe = -vec[k][i].coe;
            vec[z].push_back(vec[k][i]);
        } else {
            if(isAdd)
            vec[z][w].coe += vec[k][i].coe;
            else
            vec[z][w].coe -= vec[k][i].coe;
        }
    }
}

void mul(int k) {
    for(int i = 0; i < vec[k].size(); i++) {
        for(int j = 0; j < vec[0].size(); j++) {
            int w = search(101, vec[k][i].exp + vec[0][j].exp);
            if(w == -1)
            vec[101].push_back(item(vec[k][i].coe* vec[0][j].coe
            , vec[k][i].exp + vec[0][j].exp));
            else {
                vec[101][w].coe += vec[0][j].coe * vec[k][i].coe;
            }
        }
    }
    vec[0] = vec[101];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    double a, b;
    for(int j = 0; j < T; j++) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            int k = search(j, b);
            if(k == -1)
            vec[j].push_back(item(a, b));
            else {
                vec[j][k].coe += a;
            }
        }
    }
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '+') addOrSub(0, i + 1, true);
        if(s[i] == '-') addOrSub(0, i + 1, false);
        if(s[i] == '*') mul(i + 1);
    }
    sort(vec[0].begin(), vec[0].end());
    bool first = 0;
    for(int i = 0; i < vec[0].size(); i++) {
        if(vec[0][i].coe == 0) continue;
        if(first) {
            if(vec[0][i].coe > 0) cout << "+";
        }
        if(abs(vec[0][i].coe) != 1 || vec[0][i].exp == 0) cout << vec[0][i].coe; 
        if(vec[0][i].exp != 0)
        cout << "x";
        if(vec[0][i].exp != 1 && vec[0][i].exp != 0)
        cout << "^" << vec[0][i].exp;
        first = true;
    }
    cout << endl;
    return 0;
}