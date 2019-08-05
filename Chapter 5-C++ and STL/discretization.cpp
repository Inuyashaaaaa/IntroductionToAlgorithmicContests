#include<iostream>
#include<algorithm>
using namespace std;

int a[] = {1,122,33,12134,123123,122,33,33,4};
int b[] = {1,122,33,12134,123123,122,33,33,4};

int main() {

    int n = 9;
    sort(a, a + n);
    int size = unique(a, a + n) - a; //离散化后的元素个数
    cout << "离散化后的数字" <<endl;
    for(int i = 0; i < size; i++) {
        cout << i << ":" << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        int k = lower_bound(a,a+size,b[i]) - a ;
        cout << k << ":" << b[i] << endl;
    }

    system("pause");
    return 0;
}