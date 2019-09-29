#include <iostream>
using namespace std;
struct strong{
    int ai;
    strong *next;
};
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n = 0, max = 0;
    cin>>n;
    strong *bottom = NULL;
    strong *current = NULL;
    strong *pre = NULL;
    for (int i = 0; i < n; i++ ){
        if ( bottom == NULL){
            bottom = new strong;
            cin>>bottom->ai;
            pre = bottom;
        }else{
            current = new strong;
            cin>>current->ai;
            current->next = pre;
            pre = current;
        }
    }
    max = current->ai;
    pre = current;
    current = current->next;
    for (int i = 0; i < n; i++){
        cout << i << endl;
        cout << pre << " " << current << endl;
        if((pre->ai) < (current->ai)){
            if(max < pre->ai + current->ai)
                max = pre->ai + current->ai;
        }else{
            if(pre->ai > max)
                max = pre->ai;
        }
        pre = current;
        current = current->next;
    }
    cout<< max<<endl;
    return 0;
}
