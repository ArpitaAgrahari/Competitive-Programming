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
void print_linked_list(struct node* first){
    while(first!=NULL){
        cout<<first->data<<" ";
        first=first->next;
    }
}
