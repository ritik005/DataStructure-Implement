#include <iostream>
#include <math.h>

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

// GETTING HEIGHT OF A BINARY TREE

int height(node*root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
void printIn(node*root){
    if(root == NULL){
        return;
    }
    printIn(root->left);
    cout << root->data <<" ";
    printIn(root->right);
}
// PRINT THE KTH LEVEL
void printKthLevel(node*root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout << root->data <<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}
// PRINT ALL LEVEL
void printAlllevel(node*root){
    int h = height(root);
    for(int i = 1; i <= h ; i++){
         printKthLevel(root, i);
         cout << endl;
    }
    return;
}

int main() {
    node*root = buildTree();
    // TIME COMPLEXITY IS O(N*N);
    printAlllevel(root);
    return 0;
}