#include <stdio.h>
#include <stdlib.h>
//node structure
typedef struct node{
int data ;
struct node * next ;
}node;
//allocate memory for a new node 
node * get_node(int d){
node * newnode = malloc(sizeof(node)) ;
newnode->data = d  ;
newnode->next= NULL ;
return newnode ;
};
//adds an elelment at the beginning of the list
void add_at_beg(node ** head , int d){
if(head ==NULL){
    *head = get_node(d) ;
}
else{
node* newnode = get_node(d) ;
newnode->next  = *head ;
*head = newnode ;
}
};
//adds an element at the end of the list
void add_at_end(node ** head , int d ){
    if(*head==NULL){
        *head = get_node(d) ;
    }
    else{
    node * newnode = get_node(d) ;
    node *ptr = *head ;
    while(ptr->next !=NULL){
        ptr = ptr->next ;
    }
    ptr->next = newnode ;
    }
}
//returns the number of nodes in a linked list
int list_size(node *head){
node * ptr = head ;
int count = 0 ;
while(ptr!=NULL){
    ptr = ptr->next;
    count++;
}
return count ;
}
//adds a node at a certain position
void add_at_pos(int d,int pos,node ** head){
if(pos<0||pos>(list_size(*head)+1)){
    printf("\nInvalid");
    return;
}
else {
    if(pos ==0){
        add_at_beg(head,d) ;
    }
    else if(pos>list_size(*head)){
        add_at_end(head,d) ;
    }
    else {
    node * newnode = get_node(d) ;
      node * ptr = *head  ;
        while(pos>1){
            pos-- ;
            ptr = ptr->next  ;
        }
        newnode->next  =ptr->next ;
        ptr->next = newnode ;
}
}
};
//display the data in the list
void showlist(node * head){
puts("") ;
while(head!=NULL){
    printf("%d ",head->data) ;
    head = head->next ;
}
}
//deletion of 1st node then assigning the new head 
void delfirst(struct node ** head ){
if(*head ==NULL){
        return;
}
else if((*head)->next ==NULL) {
    free(*head) ; *head = NULL ;
}
else{
    node* temp = *head ;
    *head = (*head)->next ;
    free(temp) ; temp = NULL;
}
};
//deletion of last node
void dellast(struct node ** head ){
if(head ==NULL){
    return ;
}
else if((*head)->next ==NULL){
   free(*head) ; head = NULL ;
}
else {
    node  *ptr = *head ;
    while(ptr->next->next!=NULL ){
        ptr = ptr ->next ;
    }
    free(ptr->next);
    ptr->next = NULL ;
}
};
//deletes a node based on the data in it 
node * del_data(int d  ,struct node * head){
if(head ==NULL||head->data ==d){
   delfirst(&head) ;
return head ;
}
else {
node *ptr = head ;
while(ptr->next!=NULL){
    if(ptr->next->data ==d ){
        node * temp = ptr->next;
        ptr->next = ptr->next->next ;
        free(temp) ; temp = NULL ;
    }
ptr = ptr->next;
}
}
return head ;
}
//deletes a certain node
void del_at_pos(int  pos ,node ** head){
if(pos<0||pos>=(list_size(*head))){
    printf("Invalid");
return ;
}
else {
    if(pos ==0){
       delfirst(head) ;
    }
    else if(pos>list_size(*head)){
        dellast(head) ;
    }
    else {
      node * ptr =*head  ;
        while(pos>1){
            pos-- ;
            ptr = ptr->next  ;
        }
        node *temp = ptr->next ;
        ptr->next = ptr->next->next;
        free(temp) ; temp = NULL ;
}
}
};
//deletes all nodes of the list and assigning each to NULL
node* del_all(struct node *head){
    node * second = (head)->next ;
    while(second!=NULL){
    free(head) ;
    head = NULL ;
    head = second ;
    second= second->next ;
}
free(head) ; head = NULL ;
return head ;
}
//reverese the nodes of the linked list
struct node * reverse(struct node *head){
int n = list_size(head) ;
if(n<2){
    return head;
}
else{
node * prev = head->next  ;
node * second = head->next->next ;
head->next = NULL ;
while(head!=NULL){
prev->next =head ;
head = prev ;
prev = second;
second = second->next ;
}
head = prev;
}
return head ;
};
//switches the links of 2 nodes (not very usefull i guess )
void switch_nodes(node **prev,node**pnext){
if(prev&&pnext){
(*prev)->next = (*pnext)->next;
(*pnext)->next = (*prev);
}
}
//returns pointer to smalles element in the list
node * get_smallest(node *head){
node * psmall = head ;
while(head){
if(psmall->data<head->data){
    psmall= head ;
}
head = head->next ;
}
return psmall ;
}
//insert elements in order (smaller to greater)
void order_insert(node **head ,int data){
if(*head){
node *newnode =get_node(data);
node *ptr = *head ;
while((ptr->next!=NULL)&&newnode->data>ptr->next->data){
    ptr = ptr->next ;
}
if(ptr==*head){
newnode->next = *head;
*head = newnode ;
}
else{
newnode->next= ptr->next ;
ptr->next = newnode ;
}
}
else{
    //head is NULL so allocate memory for it
    *head = get_node(data);
}
}
int main()
{
struct node * head = NULL  ;
add_at_end(&head,10) ;
add_at_end(&head,9) ;
add_at_end(&head,2) ;
add_at_end(&head,1) ;
add_at_end(&head,0) ;
add_at_end(&head,15) ;
add_at_end(&head,19) ;
showlist(head) ;
head = del_all(head);
showlist(head);
    return 0;
}
