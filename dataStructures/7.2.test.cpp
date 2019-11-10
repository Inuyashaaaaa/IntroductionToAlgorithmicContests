/*
1、insert a b 加入复数 a+bi 如果该复数已存在，则忽略该操作。反之，成功加入后，输出当前集合的大小。
2、delete a b 删除复数 a+bi 如果该复数不存在，则忽略该操作。反之，成功删除后，输出当前集合的大小。
3、pop m 删除集合中模长为m的复数，并输出当前集合的大小。
4、value 输出当前病毒的破坏力。
（病毒的破坏力value定义为：集合中所有的复数求和，和的模长平方即为value。
比如集合中有{1+2i，-3+4i}, 求和后得 -2+6i, 则value = (-2)(-2) + 66 = 40）
★数据输入 输入第一行为一个正整数n表示调试次数。 
接下来n行，每行为上述4种操作之一。 1≤ n ≤100000， -1000≤ a,b ≤1000, 0≤ m ≤10^9 且a,b,m都为整数 
★数据输出 按顺序输出每次的调试信息（被忽略的操作不用输出），具体格式见输出示例。
*/


#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    cout << 100000 << endl;
    for(int i = 0; i < 100000; i++) {
        int c = rand() % 4;
        int a, b, m;
        a = rand() % 2001 - 1000;
        b = rand() % 2001 - 1000;
        m = sqrt(a * a + b * b);
        if(c == 0) {
            cout << "insert" << " " << a << " " << b << endl;
        }
        if(c == 1) {
            cout << "delete" << " " << a << " " << b << endl;
        }
        if(c == 2) {
            cout << "pop" << " " << m << endl;
        }
        if(c == 3) {
            cout << "value" << endl;
        }
    }
    
    return 0;
}