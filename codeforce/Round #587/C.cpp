#include<bits/stdc++.h>
#define LL long long
using namespace std;
int pic[6][6];
int x1, x2, y1, y2, x3, y3, x4, y4, x5, y5, x6, y6;
int x[6];
int y[6];
int n1 = 6;
int n2 = 6;

/*离散化*/
void discretization(int* a, int& n) {
	sort(a, a + n);
	n = unique(a, a + n) - a;
}

int getId(int* a, int n, int k) {
	return lower_bound(a, a + n, k) - a;
}

void cover() {
    int id1 = getId(x, n1, x3);
    int id2 = getId(x, n1, x4);
    int id3 = getId(y, n2, y3);
    int id4 = getId(y, n2, y4);
    //cout << id1 << " " << id2 << endl << id3 << " " << id4 << endl;
    for(int i = id1; i < id2; i++) {
        for(int j = id3; j < id4; j++) {
            pic[i][j] = 1;
        }
    }
    id1 = getId(x, n1, x5);
    id2 = getId(x, n1, x6);
    id3 = getId(y, n2, y5);
    id4 = getId(y, n2, y6);
    for(int i = id1; i < id2; i++) {
        for(int j = id3; j < id4; j++) {
            pic[i][j] = 1;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(pic, 0, sizeof(pic));
    for(int i = 0; i < n1; i++) {
        cin >> x[i] >> y[i];
    }
    x1 = x[0], y1 = y[0];
    x2 = x[1], y2 = y[1];
    x3 = x[2], y3 = y[2];
    x4 = x[3], y4 = y[3];
    x5 = x[4], y5 = y[4];
    x6 = x[5], y6 = y[5];

    discretization(x, n1);
    discretization(y, n2);
    // for(int i = 0; i < n1; i++) {
    //     cout << x[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n2; i++) {
    //     cout << y[i] << " ";
    // }
    // cout << endl;
    // cout << endl;
    cover();
    bool isCover = true;
    int id1 = getId(x, n1, x1);
    int id2 = getId(x, n1, x2);
    int id3 = getId(y, n2, y1);
    int id4 = getId(y, n2, y2);
    for(int i = id1; i < id2; i++) {
        for(int j = id3; j < id4; j++) {
            if(!pic[i][j]) {
                isCover = false;
                break;
            }
        }
    }
    cout << (isCover ? "NO" : "YES") << endl;



    
    return 0;
}