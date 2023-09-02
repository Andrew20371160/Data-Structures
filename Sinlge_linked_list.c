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
//add an element at 1st
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
//add an element at last
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
//gets size of a list
int list_size(node *head){
node * ptr = head ;
int count = 0 ;
while(ptr!=NULL){
    ptr = ptr->next;
    count++;
}
return count ;
}
//add a function at a certain position
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

//show elements of the list
void showlist(node * head){
puts("") ;
while(head!=NULL){
    printf("%d ",head->data) ;
    head = head->next ;
}
}
//deletes first node of the list
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
//deletes last element of the list
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
//deletes a node of a certain data
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
//deletes a certain position in the list
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
//deletes all the nodes of the list
node* delall(struct node *head){
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
//reverse all the nodes of the list
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
//this function reverse the node with the sent data if found
//with the next node to that node
void reverse_2_nodes(int data ,node ** head){
//if the sent data is data of the 1st node
//this code handles this while assigning the new head
if(data == (*head)->data){
node *p2 = (*head)->next ;
(*head)->next = p2->next;
p2->next= (*head) ;
(*head) = p2  ;
}
else{
    node * p1 = *head ;
    //this flag indicates if the element is found
    //the loop goes until p1 is pointing at last element
    //so we can't switch it with NULL
    unsigned char flag = 0 ;
    while(p1->next!=NULL){
        if(p1->next->data==data){
            flag = 1 ;
            break ;
        }
        p1 =p1->next;
    }
    if(flag){
    node *p2 = p1 ->next;
    if(p2->next!=NULL){
    p1->next =p2->next ;
    p2->next= p2->next->next ;
    p1->next->next= p2;
    }
}
}
}
//returns pointer of the smallest element
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

int main()
{
struct node * head = NULL  ;
order_insert(&head,10) ;
order_insert(&head,9) ;
order_insert(&head,2) ;
order_insert(&head,1) ;
order_insert(&head,0) ;
order_insert(&head,15) ;
order_insert(&head,19) ;
order_insert(&head,-1);
order_insert(&head,20);
showlist(head) ;
reverse_2_nodes(19,&head);
showlist(head);

head = delall(head);
    return 0;
}
