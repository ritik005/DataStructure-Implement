#include <iostream>
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
void BFS(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout << f->data << " ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
        }
    }
    return;
}
node* deletionInBST(node*root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root->left = deletionInBST(root->left, data);
        return root;
    }
    else if(data == root->data){
        //1.
        if(root->left == NULL && root->right == NULL ){
            delete root;
            return NULL;
        }
        //2.
        if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            node*temp = root->right;
            delete root;
            return temp; 
        }
        //3.
        node*replace = root->right;
        // Find the inorder successor
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deletionInBST(root->right, replace->data);
        return root;

    }
    else {
        root->right = deletionInBST(root->right, data);
        return root;
    }
}
int main(){
    node*root = build();
    int s;
    cin >> s;
    root = deletionInBST(root, s);
    BFS(root);
    return 0;
}
