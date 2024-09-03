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
    first=delete_at_first(first);
    print_linked_list(first);
    return 0;
}
