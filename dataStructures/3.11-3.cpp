#include <bits/stdc++.h>

using namespace std;
struct Item{
    int left,
        right,
        value;
    Item(int v):value(v),right(v),left(0){}
};
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n) {
        int i = 0,num,res = 0;
        int sonLeft = 0;//第n个元素出栈时，n+1个元素未被读取，用sonLeft储存需要继承的左边界
        vector<Item> happ;
        vector<Item> stack;

        for(i = 0;i < n;i++){
            cin >> num;
            happ.push_back(Item(num));
        }
        happ.push_back(Item(0));
        i = 0;
        while(i <= n){
            if(!stack.size() || happ[i].value>=stack.back().value){
                happ[i].left = sonLeft;
                sonLeft = 0;
                stack.push_back(happ[i++]);
            }else{
                Item top = stack.back();
                stack.pop_back();
                if(!stack.empty())
                    stack.back().right += top.right;
                sonLeft += (top.value + top.left);
                res = max(res,top.value*(top.left+top.right));
            }
        }
        cout << res << endl;
    }
}
