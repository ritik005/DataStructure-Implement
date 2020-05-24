#include <iostream>
#include <queue>
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
class HbalaPair {
    public:
        int height;
        bool balance;
};
HbalaPair isHeight(node*root){
    HbalaPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HbalaPair left = isHeight(root->left);
    HbalaPair right = isHeight(root->right);

    p.height = max(left.height, right.height) + 1;
    if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}
// BUILD A HEIGHT BALANCED TREE FROM ARRAY

node* BuildTreeFromArray(int *a, int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s + e) / 2;
    node* root = new node(a[mid]);
    root->left = BuildTreeFromArray(a, s, mid - 1);
    root->right = BuildTreeFromArray(a, mid + 1, e);
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
int main() {
    node*root = buildTree();
    // CHECKING TREE IS BALANCED OR NOT

    if(isHeight(root).balance){
        cout << "Balanced";
    }
    else {
        cout << "Not Balanced";
    }
    // BUILD HEIGHT BALANCED TREE FORM ARRAY
    int a[ ] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n = 10;
    node* root = BuildTreeFromArray(a,0,n-1);
    BFS(root);
    return 0;
}