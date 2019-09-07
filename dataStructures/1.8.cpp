#include<bits/stdc++.h>
#define LL long long
using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<int> vec3;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    int temp = 0;
    while(n--) {
        cin >> x;
        temp ^= x;
        vec1.push_back(x);
    }
    int cnt = 0;
    int tmp = temp;
    while(1) {
        if((temp & 1) == 1) 
        break;
        cnt++;
        temp>>=1;
    }
    for(int i = 0; i < vec1.size(); i++) {
        if(vec1[i]>>cnt & 1) {
            vec2.push_back(vec1[i]);
        } else {
            vec3.push_back(vec1[i]);
        }
    }
    int ans1 = 0;
    for(int i = 0; i < vec2.size(); i++) {
        ans1 ^= vec2[i];
    }
    int ans2 = (tmp ^ ans1);
    if(ans1 > ans2)
        swap(ans1, ans2);
    cout << ans1 << " " << ans2 << endl;


    return 0;
}