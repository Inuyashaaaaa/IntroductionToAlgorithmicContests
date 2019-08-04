#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int maxrow = 10100;
const int maxcol = 15;

string map[maxrow][maxcol];

int main() {
    //freopen("5-9.in","r",stdin);
    //freopen("5-9.out","w",stdout);
    int rows, cols;
    while(cin >> rows >> cols) {
        getchar();
        for(int i = 0; i < rows ; i++) {
            for(int j = 0; j < cols; j++) {
                string s;
                while(1) {
                    char ch;
                    ch = getchar();
                    if(ch == ',' || ch == '\n')
                    break;
                    s += ch;
                }
                map[i][j] = s;
            }
        }

        unordered_map<string,int> uMap;
        int r1 = -1 , r2 = -1;
        int c1 = -1 , c2 = -1;
        for(int i = 0; i < cols - 1; i++) {
            for(int j = i + 1; j <cols ; j++) {
                uMap.clear();
                for(int k = 0; k < rows ; k++) {
                    if(uMap.count(map[k][i] + ',' + map[k][j])) {
                        r1 = uMap[map[k][i] + ',' + map[k][j]];
                        r2 = k;
                        c1 = i;
                        c2 = j;
                        break;
                    }
                    else {
                        uMap[map[k][i] + ',' + map[k][j]] = k;
                    }
                }
                if(r1 != -1)
                break;
            }
            if(r1 != -1)
            break;
        }

        if(r1 != -1) {
            cout << "NO" << endl;
            cout << r1 + 1 << " " << r2 + 1 << endl;
            cout << c1 + 1 << " " << c2 + 1 << endl;
        }
        else {
            cout << "YES" << endl;
        }
        
    }
    //system("pause");
    return 0;
}