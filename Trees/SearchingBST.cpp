#include <iostream>
#include <queue>
using namespace std;
// SEARCHING IN A BST O(LOGN)
class node {
public:
    int data;
    node* left;
    node* right;

    // constructor
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
bool search(node*root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    // Recursive case
    if(data <= root->data){
       return search(root->left, data);
    }
    else{
       return search(root->right, data);
    }
}

int main(){
    node*root = build();
    int s;
    cin >> s;
    if(search(root,s)){
        cout << "Found";
    }
    else {
        cout << "Not found";
    }
    return 0;
}