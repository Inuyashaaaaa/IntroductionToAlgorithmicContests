#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Matrix {
    int a, b;
    Matrix(int a = 0,int b = 0):a(a),b(b) {}
}m[26];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    while(n--) {
        char ch;
        cin >> ch;
        int k = ch - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while(cin >> expr) {
        int ans = 0;
        stack<Matrix> s;
        bool error = false;
        for(int i = 0; i < expr.length(); i++){
            if(isalpha(expr[i])){s.push(m[expr[i] - 'A']);}
            else if(expr[i] == ')') {
                Matrix m1 = s.top(); s.pop();
                Matrix m2 = s.top(); s.pop();
                if(m1.a != m2.b) {error = true; break;}
                ans += m2.a * m2.b * m1.b;
                s.push(Matrix(m2.a, m1.b));
            }
        }
        if(error) cout << "error" << endl;
        else cout << ans << endl;
    }
}