//reverse the linked list not print the reverse of linked list we have to reverse the linked list
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
void reverse_linked_list(struct node** first){
    struct node* prev=NULL;
    struct node* current=*first;
    struct node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *first=prev;
}

struct node* insert_at_first(struct node* first,int key){
    struct node* temp=new node;
    temp->data=key;
    temp->next=NULL;
    if(first==NULL)
    return temp;
    temp->next=first;
    return temp;
}
void print_linked_list(struct node* first){
    while(first!=NULL){
        cout<<first->data<<" ";
        first=first->next;
    }
}

int main(){
    node* first=NULL;
    first=insert_at_first(first,10);
    first=insert_at_first(first,20);
    first=insert_at_first(first,30);
    first=insert_at_first(first,40);
    first=insert_at_first(first,50);
    first=insert_at_first(first, 60);
    reverse_linked_list(&first);
    print_linked_list(first);
    return 0;
}
