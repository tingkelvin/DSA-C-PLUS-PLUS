#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node** head, int data){
    struct Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = *head;
    *head = newNode;
}

struct Node *search(struct Node* head, int value){
    struct Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data << endl;
        if (tmp->data == value){
            cout << "found" << endl;
            return tmp;
        }
        tmp = tmp -> next;
    }
    return NULL;
}

void remove(struct Node **head, int value){
    struct Node* tmp = *head;
    if(tmp != NULL && tmp->data == value){
        *head = tmp->next;
    }
    while(tmp != NULL && tmp->next != NULL){
        if ((tmp->next)->data == value){
            cout << tmp->data << endl;
            tmp->next = (tmp->next)->next;
            return;
        }
        tmp = tmp->next;
    }
}

void traverse(struct Node *head){
    struct Node* tmp = head;

    while(tmp != NULL){
        cout << tmp->data << "->";
        tmp = tmp -> next;
    }
    cout << endl;
}


int main(){
    struct Node* head = NULL; 
    push(&head, 20); 
    push(&head, 30); 
    // struct Node** head2 = &head; 
    // cout << head->data << endl;
    // cout << **head2->data << endl;
    remove(&head, 20);
    traverse(head);
    // cout << (prev == NULL) << endl;
    return 0;
}