#include<iostream>
#include<stack>
using namespace std;

const int MAXN = 1010;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n && n) {
        while (cin >> a[1]){
            stack<int> s;
            if(a[1] == 0)
            break;
            for(int i = 2; i <= n; i++) {
                cin >> a[i];
            }
            int A = 1;
            int B = 1;
            bool ok = true;
            while(B <= n) {
                if(A == a[B]) { A++; B++;}
                else if(!s.empty() && s.top() == a[B]) {
                    s.pop();
                    B++;
                }
                else if(A <= n) {s.push(A++);}
                else {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}