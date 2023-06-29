#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data ;
struct node * next ;
}node;
node*get_node(int d ){
node * temp = malloc(sizeof(node))  ;
temp->data =d ;
temp->next = NULL;
return temp ;
}
void sort_at_insertion(int d ,node**head){
if(*head==NULL){
    (*head) = get_node(d)  ;
    return;
}
node*newnode= get_node(d);
 if(d<=(*head)->data){
    newnode->next = *head ;
    *head=newnode  ;
}
else {
    if((*head)->next==NULL){
        (*head)->next = newnode ;
    return ;
    }
    else{
    node*ptr = *head;
    do{
        if(ptr->next->data>d){
                break ;
        }
        ptr =ptr->next;
    }while(ptr->next!=NULL);
    if(ptr->next ==NULL){
        ptr->next = newnode;
    }
    else{
        newnode->next = ptr->next ;
        ptr ->next = newnode ;


}
}
}
}
void showlist(node*head){
if(head==NULL){
    return ;
}
else {
    node * ptr = head ;
    puts("");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next ;
    }
}
}
node * delall(node*head){
if(head==NULL){
        return head ;
}
else if(head->next==NULL){
    free(head); head = NULL ;
}
else{
    node *temp=head ;
    while(head!=NULL){
    temp = head ;
    head = head ->next ;
    free(temp) ; temp = NULL;
}
}
return head ;
}
int main()
{
node * head = NULL ;
sort_at_insertion(9,&head);
sort_at_insertion(18,&head);sort_at_insertion(99,&head);

sort_at_insertion(11,&head);
sort_at_insertion(0,&head);
sort_at_insertion(2,&head);
showlist(head) ;

    return 0;
}
