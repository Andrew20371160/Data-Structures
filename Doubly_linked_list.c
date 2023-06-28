#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int data ;
struct node * next ,*prev ;
}node ;
node*get_node(int d){
node * newnode = malloc(sizeof(node));
newnode->next= NULL ;
newnode->prev = NULL ;
newnode->data =d  ;
return newnode ;
}
void add_at_beg(int d ,node**head){
if(*head==NULL){
    (*head)  =get_node(d) ;
}
else {
    node * newnode = get_node(d) ;
    newnode->next = (*head) ;
    (*head)->prev = newnode ;
    (*head)= newnode;
}
}
void add_at_end(int d, node**head){
if(*head ==NULL){
    *head = get_node(d)  ;
}
else if((*head)->next==NULL){
    node * newnode =get_node(d) ;
newnode->prev= *head ;
(*head)->next= newnode;
}
else {
    node * ptr = *head ;
    while(ptr->next !=NULL){
        ptr = ptr->next ;
    }
    node*newnode = get_node(d) ;
    newnode->prev = ptr ;
    ptr ->next = newnode;
}
}
int list_size(node*head){
int count = 0 ;
while(head!=NULL){
    count++  ;
    head = head ->next ;
}
return count ;
}
void add_at_pos(int d ,int pos, node**head){
int n= list_size(*head);
if(pos<0||pos>(n)){
    printf("\nInvalid");
    return ;
}
else{
if(pos==0){
    add_at_beg(d,head);
}
else if(pos==n){
    add_at_end(d,head);
}
else {
    node*ptr = *head ;
    node *newnode= get_node(d) ;
    while(pos>1){
        ptr = ptr->next ;
        pos--;
    }
    newnode->prev = ptr ;
    newnode->next = ptr->next ;
    ptr->next->prev = newnode;
    ptr->next = newnode;
}
}

}
void display(node*head){
if(head==NULL){
    return ;
}
else {
    puts("");
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next ;
    }
}
}
void display_rev(node*head){
while(head->next !=NULL){
    head=  head->next ;
}
while(head!=NULL ){
    printf("%d ",head->data);
    head = head->prev ;
}
}
void delfirst(node**head){
if(*head==NULL){
    printf("\nEmpty list");
}
else if((*head)->next==NULL){
    free(*head) ; *head = NULL;
}
else {
    *head = (*head)->next ;
    free((*head)->prev);
    ((*head)->prev) =NULL;
(*head)->prev = NULL ;
}
}
void dellast(node**head){
if(*head==NULL){
    printf("\nEmpty list");
}
else if((*head)->next==NULL){
    free(*head) ; *head = NULL;
}
else {
    node *ptr = *head ;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->prev->next =NULL;
    ptr->prev= NULL;
    free(ptr); ptr = NULL;
}
}
void delpos(int pos , node **head){
int n= list_size(*head);
if(pos<0||pos>(n)){
    printf("\nInvalid");
    return ;
}
else{
if(pos==0){
    delfirst(head);
}
else if(pos==n-1){
    dellast(head);
}
else {
    node*ptr = *head ;
    while(pos>0){
        ptr = ptr->next ;
        pos--;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev = ptr->prev ;
    free(ptr) ; ptr = NULL;

}
}
}
//gamda de
node *  reverse(node*head) {
int n= list_size(head) ;
if(n<2){
    return head;
}
else {
node *ptr = head->next  ;
head->next = NULL;
while(ptr!=NULL){
    head->prev = ptr ;
    head=ptr ;
    ptr = ptr->next ;
    head->next= head->prev;
}
head->prev = NULL ;
}
return head;
}


int main()
{
node * head = NULL ;
for(int i=0 ; i <10 ; i ++){
 add_at_end(i+1,&head);
}
display(head);
head = reverse(head) ;
display(head);
display_rev(head) ;
    return 0;
}
