#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    while(cin >> k) {
        vec.clear();
        for(int y = k + 1; y <= 2 * k ; y++) {
            int x = (k * y) / (y - k);
            int e = (k * y) % (y - k);
            if(!e)
                vec.push_back(make_pair(x, y));        
        }
        cout << vec.size() << endl;
        for(auto& pair : vec) {
            cout << "1/" << k << " = " << "1/" <<
            pair.first << " + " << "1/" << pair.second
            << endl;
        }
    }
    return 0;
}