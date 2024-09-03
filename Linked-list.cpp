//Singly Linked List
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
void print_Linked_List(struct node* first){
    while(first!=NULL){
        cout<<first->data<<" ";
        first=first->next;
    }
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

int main(){
    node* first=NULL;
    first=insert_at_first(first,10);
    first=insert_at_first(first,20);
    first=insert_at_first(first,30);
    first=insert_at_first(first,40);
    first=insert_at_first(first,50);
    print_Linked_List(first);
    return 0;
}