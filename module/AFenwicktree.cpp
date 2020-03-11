#include<bits/stdc++.h>
using namespace std;

class BinaryIndexedTree {
	private:
        int* bitArr;
        int length;
	public:
        BinaryIndexedTree(int* list, int length) {
            // O(n) initialization
            this -> bitArr = new int[length + 1];
            this -> length = length;
            for (int i = 0; i < length; i++) {
                this -> bitArr[i + 1] = list[i];
            }
          
            for (int i = 1; i < length; i++) {
                int j = i + (i & -i);
                if (j < length) {
                    this -> bitArr[j] += this -> bitArr[i];
                }
            }
        }
	    void update(int idx, int delta) {
            idx += 1;
            while (idx < this -> length) {
                this -> bitArr[idx] += delta;
                idx = idx + (idx & -idx);
            }
        }
	    int prefixSum(int idx) {
            idx += 1;
            int result = 0;
            while (idx > 0) {
                result += this -> bitArr[idx];
                idx = idx - (idx & -idx);
            }	
            return result;
        }
        // means [1, 13] => 数组的第一个元素到第13个元素的和
        int rangeSum(int from_idx, int to_idx) {
            return prefixSum(to_idx) - prefixSum(from_idx - 1);
        }
};

int main() {
    freopen("out.txt", "w", stdout);
    int arr[] = {1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};
    BinaryIndexedTree b(arr, 14);
    cout << b.rangeSum(1, 13) << endl;
    return 0;
}