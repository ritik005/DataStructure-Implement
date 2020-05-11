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
int len(node*head) {
    int len = 0;
    while(head!=NULL){
        head = head->next;
        len+=1;
    }
    return len;
}
// Passing a pointer variable by reference
void insertAtHead (node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}
void insertAtTails (node* &head, int data){
    if(head==NULL){
        head = new node(data); 
        // insertAtHead(head, data);
        return;
    }
    node*tails = head;
    while(tails->next!=NULL){
        tails = tails->next;
    }
    node*n = new node(data);
    tails->next = n;
    return;
}
void insertAtMiddle (node* &head, int data, int p){
    if(head == NULL || p==0){
        insertAtHead(head, data);
    }
    else if(p>len(head)) {
        insertAtTails(head, data);
    }
    else {
        int jump = 1;
        node*temp = head;
        while(jump  <= p-1){
            temp = temp->next;
            jump+=1;
        }
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}
void print(node*head) {
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    node*head = NULL;
    insertAtTails(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtMiddle(head, 2, 3);
    print(head);
    return 0;
}