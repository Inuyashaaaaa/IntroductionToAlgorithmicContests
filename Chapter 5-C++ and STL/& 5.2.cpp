#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

void findBlock(int a, int &p, int &h) {
    for(p = 0 ; p < n ; p ++){
        for(h = 0 ; h < pile[p].size(); h++){
            if(pile[p][h] == a) return;
        }
    }
    return;
}

void clearAbove(int p, int h){
    for(int i = h + 1 ; i < pile[p].size() ; i++){
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

void pileOnto(int p, int h, int p2) {
    for(int i = h ; i < pile[p].size() ; i++){
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print() {
    for(int i = 0 ; i < n; i++) {
        cout << i << ":";
        for(int j = 0 ; j < pile[i].size() ; j++) 
            cout << " " << pile[i][j];
        cout << endl;
    }
}

int main()
{
    int a, b;
    cin >> n;
    string s1, s2;
    for(int i = 0 ; i < n; i++) pile[i].push_back(i);
    while(cin >> s1 >> a >> s2 >> b) {
        int pa, pb, ha, hb;
        findBlock(a, pa, ha);
        findBlock(b, pb, hb);
        if(pa == pb) continue;
        if(s2 == "onto") clearAbove(pb, hb);
        if(s1 == "move") clearAbove(pa, ha);
        pileOnto(pa, ha, pb);
    }
    print();
    // system("pause");
    return 0;
}