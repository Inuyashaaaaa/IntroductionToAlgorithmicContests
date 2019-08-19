#include<bits/stdc++.h>
using namespace std;
vector<int> vec1;
vector<int> vec2;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }else {
        cout << "YES" << endl;
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(i % 4 == 1 || i % 4 == 0)
        vec1.push_back(i);
        if(i % 4 == 2 || i % 4 == 3)
        vec2.push_back(i);
    }
    for(auto& num: vec1) {
        cout << num << " ";
    }
    for(auto& num: vec2) {
        cout << num << " ";
    }
    cout << endl;
}