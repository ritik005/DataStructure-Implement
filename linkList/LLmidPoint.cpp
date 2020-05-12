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
// Using Runner technique - Important
node* midpoint(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*S = head, *F = head->next;
    while(F!=NULL && F->next!=NULL){
        F = F->next->next;
        S = S->next;
    }
    return S;
}
void print(node*head) {
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main(){
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    print(head);
    node*m = midpoint(head);
    cout << m->data;
    return 0;
}