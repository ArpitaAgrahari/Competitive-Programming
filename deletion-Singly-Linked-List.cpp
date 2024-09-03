//deletion in singly linked lsit 
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node* delete_at_first(struct node* first){
    if(first==NULL)
    return NULL;
    struct node* temp=first;
    first=first->next;
    delete temp;
    return first;
}
void print_linked_list(struct node* first){
    while(first!=NULL){
        cout<<first->data<<" ";
        first=first->next;
    }
}
int main(){
    node* first=NULL;
    first=new node;
    first->data=10;
    first->next=NULL;
    first=new node;
    first->data=20;
    first->next=NULL;
    first=new node;
    first->data=30;
    first->next=NULL;
    first=new node;
    first->data=40;
    first->next=NULL;
    first=new node;
    first->data=50;
    first->next=NULL;
    first=delete_at_first(first);
    print_linked_list(first);
    return 0;
}
