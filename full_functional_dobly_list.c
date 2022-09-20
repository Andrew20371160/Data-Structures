#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * next ;
struct node * prev;

};
struct node * add_at_empty(int d , struct node * head ){
head->data = d ;
head->next = NULL ;
head->prev = NULL;
return head ;
}
struct node * add_at_beg(int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp->data = d;
temp ->next = head  ;
head ->prev = temp ;
head  =temp ;

return head;
};
void  add_at_end (int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp->data  =d  ;
temp->next = NULL ;
struct node * ptr = head ;
while(ptr->next!=NULL ){
    ptr = ptr->next ;
}
ptr->next = temp ;
temp->prev = ptr ;


}
int list_size(struct node * head ){
int size = 0 ;
struct node * ptr =head ;
while(ptr !=NULL){
    size++;
    ptr = ptr->next  ;
}
return size ;


}
struct node * add_at_pos(int d , int pos ,struct node * head ){

if(head == NULL){
    head = add_at_empty(d,head) ;
    return head ;
}
else if(pos ==1 ){
    head = add_at_beg(d,head) ;
    return head ;
}
else if(pos == list_size(head)+1){
    add_at_end(d,head) ;
    return head ;
}
else {
struct node * temp = malloc(sizeof(struct node)) ;
temp->data = d ;
pos-- ;
struct node * ptr = head ;
while(pos!=1){

    ptr = ptr->next ;
pos-- ;
}
temp->next = ptr->next ;
temp->prev = ptr ;
ptr ->next = temp ;

return head ;

}
}
struct node * reverse_list(struct node * head ){
struct node * ptr = head ;
struct node * newhead = malloc(sizeof(struct node))  ;
newhead = add_at_empty(head->data,newhead) ;
ptr = ptr->next ;
while(ptr!=NULL){
newhead=add_at_beg(ptr->data ,newhead);
ptr = ptr->next ;
}
return newhead ;


}
void add_after(int d , int pos , struct node * head){
struct node * temp = malloc(sizeof(struct node))  ;
temp ->data = d;

struct node * ptr =head ;
while(pos!=1){
    ptr =ptr->next ;
    pos--;
}
temp ->next =  ptr ->next ;
temp ->prev = ptr ;
ptr ->next = temp ;

}
void add_before(int d , int pos , struct node * head){
struct node * temp = malloc(sizeof(struct node))  ;
temp ->data = d;

struct node * ptr =head ;
pos-=2;
while(pos!=1){

    ptr =ptr->next ;
        pos--;

}
temp ->next =  ptr ->next ;
temp ->prev = ptr ;
ptr ->next = temp ;

}
struct node * del_1st_node (struct node * head ){
head = head->next ;
free(head->prev) ;
head->prev = NULL ;
return head ;

};
void del_last_node(struct node * head){
struct node * ptr = head ;
while(ptr->next->next!=NULL){
    ptr = ptr->next ;
}
free(ptr->next) ;

ptr->prev = ptr->prev ;
ptr ->next = NULL ;


}
void del_node(int pos , struct node * head ){
struct node * ptr = head ;

while(pos!=1){
    ptr = ptr->next ;
    pos-- ;

}
struct node * temp2 = ptr->prev  ;
temp2 ->next =ptr ->next ;

ptr->next->prev = temp2 ;
free(ptr);



}


struct node * del_list(struct node * head){
while(head->next!=NULL){
    head=head->next ;
    free(head->prev) ;
}
head=NULL ;
return head ;

};
struct node * reverse_list2(struct node * head ){
struct node * newhead =  malloc(sizeof(struct node)) ;
newhead = add_at_empty(head->data ,newhead) ;
struct node * ptr = head->next ;
while(ptr!=NULL){
    newhead =add_at_beg(ptr->data,newhead) ;

    ptr=ptr->next ;

}
del_list(head) ;
return newhead ;

};

struct node *reverse_list3(struct node * head ){
struct node * ptr1 = head ;
struct node * ptr2 = head->next ;
ptr1->next = NULL;
ptr1->prev = ptr2 ;
while(ptr2!=NULL){
    ptr2->prev =ptr2->next  ;

    ptr2->next =  ptr1 ;
    ptr1 =ptr2 ;
    ptr2 = ptr2->prev ;

}
head = ptr1 ;
return head ;


};
int main()
{
struct node * head=  malloc(sizeof(struct node)) ;
head= add_at_empty(1,head) ;
head =add_at_beg(2,head)  ;
head =add_at_beg(33,head)  ;
add_at_end(320,head) ;
head = add_at_pos(20,1,head) ;

struct node * ptr = head  ;
while(ptr!=NULL){
    printf("%d ",ptr->data );
    ptr=ptr->next ;
}

printf("\n ");
head = reverse_list3(head);
  ptr = head  ;
while(ptr!=NULL){
    printf("%d ",ptr->data );
    ptr=ptr->next ;
}

    return 0;
}
