#include <iostream>
#include <climits>
#include <queue>

using namespace std;

class node {
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node* insertAtBST(node*root, int data){
    if(root == NULL){
        return new node(data);
    }
    if(data <= root->data){
       root->left = insertAtBST(root->left, data);
    }
    else {
       root->right = insertAtBST(root->right, data);
    }
    return root;
}
node* build(){
    int d;
    cin >> d;
    node*root = NULL;
    while(d != -1){
        root = insertAtBST(root, d);
        cin >> d;
    }
    return root;
}
bool isBST(node*root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= minV && root->data < maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)){
        return true;
    }
    return false;
}
int main() {
    node*root = build();
    if(isBST(root)){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}