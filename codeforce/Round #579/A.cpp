#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 20;
int arr[maxn];

int main() {
    int T;
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int index;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] == 1)
            {
                index = i;
            }
        }
        // 顺时针 ->
        bool flag = true;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(arr[(i+index)%n] != ++cnt){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
            continue;
        }
        flag = true;
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if(arr[(n+index-i)%n] != ++cnt){
                flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
     
    }
}