#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int d){
            data = d;
            next = NULL;
        }
};

void insertAtHead (node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}
void print(node*head){
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void deleteAtHead (node* &head){
    if(head == NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail (node* &head){
    if(head == NULL){
        return;
    }
    node*prev = NULL, *temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteAtMiddle (node* &head, int p){
    if(head == NULL){
        return;
    }
    else if(p==1){
        deleteAtHead(head);
        return;
    }
    node*prev = NULL, *temp = head;
    int jump = 1;
    while(jump < p){
        prev = temp;
        temp = temp->next;
        jump+=1;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

int main(){
    node*head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    insertAtHead(head, 9);
    insertAtHead(head, 10);
    deleteAtMiddle(head, 1);
    print(head);
}