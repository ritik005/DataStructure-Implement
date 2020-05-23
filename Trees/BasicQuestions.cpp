#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node*left;
        node*right;

        //Constructor
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node* buildTree(){
    int d;
    cin >> d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
int height(node*root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
// COUNT THE NUMBER OF NODES IN A TREE
int count(node*root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}
// FIND SUM OF ALL NODES
int sum(node*root){
    if (root == NULL){
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}
// DETERMINE THE DIAMETER - O(N*N)
int diameter(node*root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}
int main() {
    node*root = buildTree();
    cout << count(root) << endl;
    cout << sum(root) << endl;
    cout << diameter(root);

    return 0;
}