//queue using LL
//enque and dequeue
#include<iostream>
using namespace std;
 
struct node{
    int data;
    struct node *next;
};

void enque(struct node** front,struct node** rear,int key){
    struct node* temp=new node;
    temp->data=key;
    temp->next=NULL;
    if(*front==NULL && *rear==NULL){
        *front=*rear=temp;
        return;
    }
    (*rear)->next=temp;
    *rear=temp;
}
void deque(struct node** front,struct node** rear){
    if(*front==NULL)
    return;
    if(*front==*rear){
        delete *front;
        *front=*rear=NULL;
        return;
    }
    struct node* temp=*front;
    *front=(*front)->next;
    delete temp;
}
void print_queue(struct node* front){
    while(front!=NULL){
        cout<<front->data<<" ";
        front=front->next;
    }
}
int main(){
    node* front=NULL;
    node* rear=NULL;
    enque(&front,&rear,10);
    enque(&front,&rear,20);
    enque(&front,&rear,30);
    enque(&front,&rear,40);
    enque(&front,&rear,50);
    deque(&front,&rear);
    print_queue(front);
    return 0;
}
