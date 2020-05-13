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
void insertAtTail(node* &head, int data){
    if(head == NULL){
         head = new node (data);
         return;
    }
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node*n = new node (data);
    temp->next = n;
    return;
}
void buildList (node* &head){
    int data;
    cin >> data;
    while(data!=-1){
        insertAtTail(head, data);
        cin >> data;
    }
}
node* midPoint(node* head){
    if(head == NULL && head->next == NULL){
        return head;
    }
    node*s = head;
    node*f = head->next;
    while(f!=NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;
    }
    return s;
}
node* merge(node*a,node*b){
    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }
    node*c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}
node* mergeSort(node*head){
    if(head ==NULL || head->next == NULL){
        return head;
    }
    // 1- Mid point
    node*mid = midPoint(head);
    node*a = head;
    node*b = mid->next;
    mid->next = NULL;
    // 2- rec case
     a = mergeSort(a);
     b = mergeSort(b);
     // 3- Merge them
     node* c = merge(a,b);
     return c;
}
void print(node*head){
    if(head == NULL){
        return;
    }
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << "=>";
        temp = temp->next;
    }
}
int main(){
    node* head = NULL;
    buildList(head);
    head = mergeSort(head);
    print(head);
    return 0;
}