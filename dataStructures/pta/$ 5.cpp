#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 30 + 4;

int post[maxn];
int in[maxn];

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val):val(val), left(NULL), right(NULL){}
    Node(){} 
};

Node* buildTree(int postL, int postR, int inL, int inR) {
    if(postL > postR) return NULL;
    int val = post[postR];
    Node* root = new Node(val);
    int i;
    for(i = inL; i <= inR ; i++) {
        if(in[i] == val) {
            break;
        }
    }
    int num = i - inL;
    root->left = buildTree(postL, postL + num - 1, inL, i - 1);
    root->right = buildTree(postL + num, postR - 1, i + 1, inR);
    return root;
}

void preOrder(Node* root) {
    if(root == NULL) return;
    cout << " " << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }
    Node* root = buildTree(0, n - 1, 0, n - 1);
    cout << "Preorder:";
    preOrder(root);
    return 0;
}