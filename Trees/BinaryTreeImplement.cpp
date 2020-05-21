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
void print(node* root){
    if(root == NULL){
        return; 
    }
    // PREORDER TRAVERSAL
    cout << root->data<<" ";
    print(root->left);
    print(root->right);
}
void printIn(node* root){
    if(root == NULL){
        return; 
    }
    // INORDER TRAVERSAL
    print(root->left);
    cout << root->data<<" ";
    print(root->right);
}
void printPo(node* root){
    if(root == NULL){
        return; 
    }
    // POSTORDER TRAVERSAL
    print(root->left);
    print(root->right);
    cout << root->data<<" ";
}

int main() {
    node* root = buildTree();
    print(root);
    cout << endl;
    printIn(root);
    cout << endl;
    printPo(root);
    return 0;
}