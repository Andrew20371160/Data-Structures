#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int data;
struct node*next ;
}node;
node *get_node(int d){
node * newnode = malloc(sizeof(node)) ;
newnode->data = d ;
newnode->next= newnode ;
return newnode ;
}
void add_at_beg(int d , node**tail){
if(*tail==NULL){
    *tail= get_node(d) ;
}
else{
    node*newnode=get_node(d);
    newnode->next=(*tail)->next;
    (*tail)->next= newnode;
}
}
void add_at_end(int d ,node **tail){
if(*tail==NULL){
    *tail=get_node(d);
}
else{
    node*newnode=get_node(d);
    newnode->next=(*tail)->next ;
    (*tail)->next = newnode;
    (*tail) = newnode;
}
}
int list_size(node*tail){
int count =0 ;
if(tail==NULL){
    return 0 ;
}
else{
node * ptr = tail->next ;
do{
    count++;
    ptr= ptr->next ;
}while(ptr!=tail->next);
}
return count ;
}
void display(node*tail){
if(tail==NULL){
    return ;
}
puts("");
node * ptr = tail->next ;
do {
    printf("%d ",ptr->data);
    ptr= ptr->next ;
}while(ptr!=tail->next);
}
void add_at_pos(int pos,int d,node**tail){
int n= list_size(*tail);
if(pos<0||pos>n){
    printf("\nInvalid");
    return;
}
else {
    if(pos==0){
        add_at_beg(d,tail) ;
    }
    else if(pos==n){
        add_at_end(d,tail) ;
    }
    else {
        node*newnode=  get_node(d) ;
        node*ptr = (*tail)->next ;
        while(pos>1){
            pos--;
            ptr = ptr->next;
        }
        newnode->next = ptr->next ;
        ptr->next = newnode;
    }
}
}
void delfirst(node**tail){
if(*tail==NULL){
    return ;
}
else if((*tail)->next == *tail){
    free(*tail) ; *tail = NULL;
}
else{
    node * temp = (*tail)->next ;
    (*tail)->next = temp->next ;
    free(temp); temp= NULL;
}
}
void dellast(node**tail){
if(*tail==NULL){
    return ;
}
else if((*tail)->next == *tail){
    free(*tail) ; *tail = NULL;
}
else {
    node *ptr = (*tail)->next ;
    while(ptr->next!=*tail){
        ptr = ptr->next ;
    }
    ptr->next= (*tail)->next ;
    free(*tail) ; (*tail)=ptr;
}
}
void del_at_pos(int pos , node**tail){
int n= list_size(*tail);
if(pos<0||pos>=n){
    printf("\nInvalid");
    return;
}
else {
    if(pos==0){
        delfirst(tail) ;
    }
    else if(pos==n-1){
        dellast(tail) ;
    }
    else {
        node*ptr = (*tail)->next ;
        while(pos>1){
            pos--;
            ptr = ptr->next;
        }
        node*temp = ptr->next ;
        ptr->next= ptr->next->next;
        free(temp) ;temp = NULL;
    }
}
}
node * reverse (node *tail){
int n= list_size(tail) ;
if(n<2){
    return tail ;
}
else {
    node*second = tail->next->next ;
    node*prev = tail->next ;
    for(int i=0 ; i <n ;i++){
        prev->next=tail ;
        tail =prev ;
        prev= second;
        second= second->next;
    }
    //after last iteration the prev pointer will point to last node of our
    //reversed list
    tail = prev;
}
return tail ;
}
int search(int d ,node*tail){
if(tail->data==d){
    return 1;
}
else{
node*ptr = tail->next;
do{
    if(ptr->data==d){
        return 1 ;
    }
    ptr = ptr->next ;
}while(ptr!=tail);
}
return 0  ;
}


int main()
{
node*tail = NULL ;
for(int i = 0 ; i <10;i++){
    add_at_end(i+1,&tail) ;
}
display(tail) ;
printf("%d",search(17,tail));
free(tail) ; tail=NULL;
    return 0;
}
