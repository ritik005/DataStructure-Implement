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
bool detectCycle(node*head){
    node*s = head;
    node*f = head;
    while(f!=NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(f==s){
            return true;
        }
    }
    return false;
}
void cycleremoved(node* &head){
    node*s = head;
    node*f = head;
    while(f!=NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(f==s)
            break;
    }
    s = head;
    while(s->next!=f->next){
        f = f->next;
        s = s->next;
    }
    f->next = NULL;
    return;
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
int main() {
	node *head = NULL;
	buildList(head);
	node *ptr = new node(10);
	head -> next -> next -> next -> next -> next = ptr;
	ptr -> next = head -> next -> next -> next;
	if (detectCycle(head)) {
		cout << "Cycle detected" << endl;
		cycleremoved(head);
		print(head);
	} else {
		cout << "Cycle not detected" << endl;;
	}
	return 0;
}