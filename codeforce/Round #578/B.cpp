#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100 +10;
int h[maxn];
/*
5
3 0 1
 n, m, and k 
4 3 5
 */
int main()
{
    //4 10 0
    //10 20 10 20
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i = 1;i<=n;i++){
            cin >> h[i];
        }
        bool flag = true;
        for(int i = 1;i<n;i++) {
            //cout << "m" << m ;
            int w = h[i+1] - h[i];
            if(w==k){
                continue;
            }
            if(w<k) {
                if(h[i]>0)
                m+=min(k-w,h[i]);
            }
            if(w>k){
                int d = w - k;
                if(m>=d){
                    m-=d;
                    //cout << "*" << d << "*";
                }else{
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag?"YES":"NO") << endl;

    }
    return 0;
}