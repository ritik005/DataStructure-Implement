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
void reverseLL(node* &head){
    node*C = head, *P = NULL, *N;
    while(C!=NULL){
        N = C->next; // store the next node
        C->next = P; // connect to previous node
        P = C; // update
        C = N; // update
    }
    head = P;
}
void print(node*head){
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
    reverseLL(head);
    print(head);
    return 0;
}