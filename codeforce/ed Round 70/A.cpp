#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


string addBinary(string a, string b) {
    string s;
    int i = a.length() - 1;
    int j = b.length() -1;
    int e = 0;
    while (i >= 0 || j >= 0) {
        if (j >= 0) e += b.at(j--) - '0';
        if (i >= 0) e += a.at(i--) - '0';
        s += (e % 2) + '0';
        e = e / 2;
    }
    if (e != 0) s += e + '0';
    return s;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;
        int len1 = a.length();
        int len2 = b.length();
        map<string, int> Map;
        int maxn = min(int(len1 + len2) * 2, int(1e5 + 1));
        Map[addBinary(a, b)] = 0;
        for(int i = 0; i < maxn; i++) {
            b += '0';
            Map[addBinary(a, b)] = i + 1;
        }
        cout << Map.begin() -> second << endl;
    }
    
    
    system("pause");
    return 0;
}