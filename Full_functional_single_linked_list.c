#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * link ;

};
struct node * add_at_empty(int d , struct node * head ){
head = malloc(sizeof(struct node )) ;
head->link = NULL ;
head->data = d ;
return head ;

};
struct node * add_at_beg(int d ,struct node * head ){

struct node * temp = malloc(sizeof(struct node ) )  ;
temp->data = d ;
temp ->link = head ;
head = temp ;
return head ;

};
void add_at_end(int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp ->data = d ;
temp->link = NULL ;
struct node * ptr = head ;
while(ptr->link !=NULL){
    ptr  =ptr->link  ;
}
ptr ->link =temp ;


};
int list_size(struct node * head ){
int size = 0 ;
struct node * ptr = head ;
while(ptr!=NULL)  {
    size++ ;
    ptr = ptr->link ;
}
return size ;
}
struct node * add_at_pos(int d , int pos , struct node * head ){
struct node * temp = malloc(sizeof(struct node) ) ;
temp->data = d ;
if(head == NULL){
    printf("\n position doesn't exist because list is empty ");
    return head  ;
}
else if(pos >(list_size(head)+1)){
    printf("\n position doesn't exist ") ;
return head ;
}
else if(pos ==1 ){
   head =  add_at_beg(d,head) ;
    return head ;
}
else if(pos== (list_size(head)+1)) {
    add_at_end(d,head) ;
    return head ;
}
else {
    pos-- ;
    struct node * ptr = head ;
    while(pos!=1){
        ptr = ptr->link  ;
        pos --;
    }
temp->link = ptr ->link ;
ptr ->link = temp ;
return head ;

}


}
struct node * del_1st_node(struct node * head){
struct node *  ptr = head ;
head = head->link ;
free(ptr) ;
return head ;


};
void del_last_node (struct node * head ){
struct node * ptr  = head ;
while(ptr->link ->link!=NULL){
    ptr = ptr->link ;
}
free(ptr->link ) ;
ptr->link  = NULL ;


};
void del_pos(int pos , struct node * head ){
struct node * ptr = head  ;
struct node *temp = head ;

while(pos!=1){
    ptr=temp ;
    temp =temp->link ;
pos-- ;
}
ptr ->link = temp->link ;
free(temp);

}

struct node * del_list(struct node  * head){
struct node * ptr = head ;
while(head !=NULL){
    ptr = head ;
    head = head ->link ;
    free(ptr);
}
head = NULL ;
return head ;

};
struct node * reverse_list (struct node * head ){
struct node * next =head ;
struct node * prev  = NULL ;

while(head !=NULL){
    next = head->link ;
    head->link = prev ;
        prev=  head ;

    head = next ;

}
head = prev;
 return head ;

};
void bsrot(struct node * head ){
struct node * ptr1 = head ;
struct node * ptr2 = head->link  ;
while(ptr1->link!=NULL){
ptr2 =ptr1->link ;
    while(ptr2!=NULL ){
        if(ptr1->data  > ptr2->data  ){
            int temp = ptr1->data ;
            ptr1->data  = ptr2->data ;
            ptr2->data = temp ;
        }
ptr2 =ptr2->link ;
    }
ptr1= ptr1->link ;
}



}
int main()
{
struct node * head = NULL ;
head=add_at_empty(1,head) ;
head = add_at_beg(2,head) ;
head = add_at_pos(142,3,head) ;
add_at_end(45454, head ) ;
bsrot(head);
struct node * ptr = head ;

while(ptr !=NULL){
    printf(" %d ",ptr->data) ;
    ptr = ptr ->link ;
}

    return 0;
}
