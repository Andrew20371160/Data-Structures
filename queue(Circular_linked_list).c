#include <stdio.h>
#include <stdlib.h>
//node struct
typedef struct node{
int data ;
struct node*next ;
}node ;
//get memory for a new node
node *get_node(int d ){
node *newp = malloc(sizeof(node));
newp->data=d;
newp->next= newp ;
return newp ;
}
//we add last element at the end with time complexity of O(1)
void enque(int d , node **tail){
if(*tail==NULL){
    *tail= get_node(d);
}
else{
    node *newp=  get_node(d);
    newp->next= (*tail)->next;
    (*tail)->next = newp;
    (*tail)=newp;
}
}
//First element is deleted in O(1)
int deque(node**tail){
if(*tail==NULL){
    printf("\nEmpty Queue");
    return -1;
}
else{
int d = (*tail)->next->data;
if((*tail)->next ==(*tail)){
free(*tail); *tail=NULL;
}
else{
    node*temp = (*tail)->next ;
    (*tail)->next = temp->next ;
    free(temp) ; temp = NULL;
}
return d;
}
}
//show queue elements 
void show(node*tail){
if(tail==NULL){
    return;
}
else{
    node*ptr = tail->next ;
    do{
        printf("%d ",ptr->data) ;
        ptr=  ptr->next ;
    }while(ptr!=tail->next) ;
}
}
//returns first element data 
int peek(node*tail){
if(tail==NULL){
    printf("\nEmpty Queue");
    return-1;
}
return tail->next->data;
}
//save memory
void deque_all(node**tail){
while(*tail!=NULL){
    deque(tail) ;
}
}
int main()
{

    return 0;
}
