#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0X7fffffff
using namespace std;
map<int,int> Map;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, t;
    while(cin >> t){
        while(t--){       
            cin >> a;
            int ans = 0, num;
            Map.clear();
            priority_queue<int> pq;
            for(int i = 1; i <= a; i++){
                cin >> num;
                if(num % 2 == 0){
                    if(!Map[num])
                    pq.push(num);
                    Map[num]=1;
                }
            }
            while(!pq.empty()){
                int c = pq.top();
                c = c / 2;
                ans++;
                pq.pop();
                if(c % 2 == 0) {
                    if(!Map[c]) {
                        pq.push(c);
                        Map[c]=1;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}