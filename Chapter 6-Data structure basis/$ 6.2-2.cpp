#include<iostream>
#include<stack>
using namespace std;

const int MAXN = 1010;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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
                if(A > n) {
                    ok = false;
                    break;
                }
                s.push(A++);
                while(!s.empty() && s.top() == a[B]){
                    B++;
                    s.pop();
                }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}