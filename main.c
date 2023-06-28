#include <stdio.h>
#include <stdlib.h>
struct node{
int data ;
struct node * next ;
};
struct node * tail = NULL ;
struct node * get_node(int d){
struct node * newnode = malloc(sizeof(struct node)) ;
newnode->data = d  ;
newnode->next= NULL ;
return newnode ;
};
void add_at_beg(struct node ** head , int d){
if(head ==NULL){
    *head = get_node(d) ;
}

else{
struct node* newnode = get_node(d) ;
newnode->next  = *head ;
*head = newnode ;
}
};
void add_at_end(struct node ** head , int d ){
    if(*head==NULL){
        *head = get_node(d) ;
        tail = *head;

    }
    else{
    struct node * newnode = get_node(d) ;
    tail->next  = newnode ;
    tail = newnode ;
    }

}

int list_size(struct node *head){
struct node * ptr = head ;
int count = 0 ;
while(ptr!=NULL){
    ptr = ptr->next;
    count++;
}
return count ;
}
void add_at_pos(int d,int pos,struct node ** head){
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
         struct node * newnode = get_node(d) ;
      struct  node * ptr = *head  ;
        while(pos>1){
            pos-- ;
            ptr = ptr->next  ;
        }
        newnode->next  =ptr->next ;
        ptr->next = newnode ;
    }
}
};
void showlist(struct node * head){
if(head==NULL){
    printf("\nEmpty") ;
    return ;
}
puts("") ;
struct node * ptr = head ;
while(ptr!=NULL){
    printf("%d ",ptr->data) ;
    ptr = ptr->next ;
}
}
void delfirst(struct node ** head ){
if(*head ==NULL){
        return;
}
else if((*head)->next ==NULL) {
    free(*head) ; *head = NULL ;
}
else{
struct node* temp = *head ;
    *head = (*head) ->next ;
    free(temp) ; temp = NULL;

}
};
void dellast(struct node ** head ){
if(head ==NULL){
    return ;
}
else if((*head)->next ==NULL){
   free(*head) ; head = NULL ;
}
else {
   struct node  *ptr = *head ;
    while(ptr->next->next!=NULL ){
        ptr = ptr ->next ;
    }
    free(ptr->next);
    ptr->next = NULL ;

}

};
struct node * del_data(int d  ,struct node * head){
if(head ==NULL||head->data ==d){
   delfirst(&head) ;
return head ;
}
else {
struct node *ptr = head ;
while(ptr->next!=NULL){
    if(ptr->next->data ==d ){
      struct  node * temp = ptr->next;
        ptr ->next = ptr->next->next ;
        free(temp) ; temp = NULL ;
    }
    else if(ptr->next->data ==d &&ptr->next->next==NULL){
    struct   node *temp = ptr->next ;
        ptr->next=NULL ;
        free(temp);
        temp=NULL;
}
ptr = ptr->next;
}
}
return head ;
}
void del_at_pos(int  pos , struct node ** head){
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
      struct  node * ptr =*head  ;
        while(pos>1){
            pos-- ;
            ptr = ptr->next  ;
        }
        struct node *temp = ptr->next ;
        ptr->next = ptr->next->next;
        free(temp) ; temp = NULL ;
}
}
};
struct node* delall(struct node *head){

struct node * second = (head)->next ;
    while(second!=NULL){
    head->next=NULL;
    free(head) ;
    head = second ;
    second= second->next ;


}
free(head) ; head = NULL ;

return head ;
}
struct node * reverse(struct node *head){
int n = list_size(head) ;
if(n<2){
    return head;
}
else{
struct node * prev = head->next  ;
struct node * second = head->next->next ;
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

int main()
{
struct node * head = NULL  ;
for(int i = 0 ; i <15;i++ ){
add_at_end(&head,i+1) ;
}
showlist(head);
head = reverse(head) ;
showlist(head);
head = NULL ;
    return 0;
}
