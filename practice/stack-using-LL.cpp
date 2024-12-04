//stack using ll
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
void push(struct node** top,int key){
    struct node* temp=new node;
    temp->data=key;
    temp->next=*top;
    *top=temp;
}
void pop(struct node** top){
    if(*top==NULL)
    return;
    struct node* temp=*top;
    *top=(*top)->next;
    delete temp;
}
void print_stack(struct node* top){
    while(top!=NULL){
        cout<<top->data<<" ";
        top=top->next;
    }
}
int main(){
    node* top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    pop(&top);
    print_stack(top);
    return 0;
}

