#include <iostream>
#include <queue>
// convert a BST into sorted LinkedList
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
class LinkList {
    public:
        node*head;
        node*tail;
};
LinkList flatten(node*root){
    LinkList l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    if(root->left == NULL && root->right == NULL){
        l.head = l.tail = root;
        return l;
    }
    if(root->left != NULL && root->right == NULL){
        LinkList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->right != NULL && root->left == NULL){
        LinkList rightLL = flatten(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    LinkList leftLL = flatten(root->left);
    LinkList rightLL = flatten(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}
int main() {
    node*root = build();
    LinkList l = flatten(root);
    node*temp = l.head;
    while(temp != NULL){
        cout << temp->data << "-->";
        temp = temp->right;
    }
    return 0;
}