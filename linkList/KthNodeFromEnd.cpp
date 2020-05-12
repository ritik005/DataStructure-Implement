#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;   // next pointer points to whole node

        // Constructor
        node(int d) {
            data = d;
            next = NULL; // Initially next pointer is NULL 
        }
};
void insertAtHead (node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}
//Runner technique approach
node* kthEnd(node*head, int k){
    node*S = head, *F = head;
    while(k--){
        F = F->next;
    }
    while(F!=NULL){
        F = F->next;
        S = S->next;
    }
    return S;
}
void print(node*head) {
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }
}
int main(){
    node*head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 4);
    node*K = kthEnd(head, 4);
    cout << K->data;
    return 0;
}