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
void insertAtHead(node*& head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}
node* reverseRecLL(node*head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node* smallhead = reverseRecLL(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallhead;
}
void print(node* head){
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int main() {
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    head = reverseRecLL(head);
    print(head);
    return 0;
}