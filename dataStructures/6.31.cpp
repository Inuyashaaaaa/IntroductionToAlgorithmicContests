#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];

// ▲
// arr must begin with index:1
// T must support operator +
template <class T>
class SegmentTree {
public:
    SegmentTree(T* arr, int n) {
        ele = n;
        tree = new T[4 * n];
        buildTree(1, 1, n, arr);
    }

    int query(int l, int r) {
        return query(1, 1, ele, l, r);
    }

    void add(int l, int r, int num) {
        add(1, 1, ele, l, r, num);
    }

private:
    T* tree;
    int ele;    //the amount of elements

    void add(int index, int l, int r, int addL, int addR, int num) {
        if(l == r) {
            tree[index] += num;
            return;
        }

        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);
        int mid = l + (r - l) / 2;

        if(addL > mid) {
            add(rightChildIndex, mid + 1, r, addL, addR, num);
        }
        else if(addR <= mid) {
            add(leftChildIndex, l, mid, addL, addR, num);
        } else {
            add(leftChildIndex, l, mid, addL, mid, num);
            add(rightChildIndex, mid + 1, r, mid + 1, addR, num);
        }
        tree[index] = tree[leftChildIndex] + tree[rightChildIndex];
    }

    int query(int index, int l, int r, int queryL, int queryR) {
        if(l == queryL && r == queryR) {
            return tree[index];
        }

        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);
        int mid = l + (r - l) / 2;

        if(queryL > mid) {
            return query(rightChildIndex, mid + 1, r, queryL, queryR);
        }
        else if(queryR <= mid) {
            return query(leftChildIndex, l, mid, queryL, queryR);
        } else {
            return query(leftChildIndex, l, mid, queryL, mid) + 
            query(rightChildIndex, mid + 1, r, mid + 1, queryR);
        }
        
    }
    int leftChild(int index) {
        return index * 2;
    }
    int rightChild(int index) {
        return index * 2 + 1;
    }
    // [l, r]
    void buildTree(int index, int l, int r, T* data) {
        if(l == r) {
            tree[index] = data[l];
            return;
        }
        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);
        int mid = l + (r - l) / 2;
        buildTree(leftChildIndex, l, mid, data);
        buildTree(rightChildIndex, mid + 1, r, data);
        tree[index] = tree[leftChildIndex] + tree[rightChildIndex];
    }


};

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n ;i++) {
        cin >> arr[i];
    }
    SegmentTree<int> seg(arr, n);
    while(m--) {
        char ch;
        cin >> ch;
        if(ch == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << endl;
        } 
        else if(ch == 'C') {
            int l, r, num;
            cin >> l >> r >> num;
            seg.add(l, r, num);
        }
    }
    return 0;
}