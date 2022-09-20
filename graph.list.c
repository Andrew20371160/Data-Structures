#include <stdio.h>
#include <stdlib.h>
struct node {
int data  ;
int weight ;
struct node * next ;
};struct node * ptr[8];
struct node * add_at_empty(int  d,int weight ){
struct node * head = malloc(sizeof(struct node));
head->data = d ;
head->weight = weight  ;
head->next =NULL ;
return head  ;
};
struct node * insert(int d ,int weight , struct node * head ){
if(head ==NULL){
    head = add_at_empty(d,weight) ;
    return head;
}
else if (head->next ==NULL){
    struct node * temp = add_at_empty(d,weight )  ;
    temp->next =NULL;
    head ->next = temp ;
    return head ;

}
else {
struct node * ptr  = head ;
while(ptr->next !=NULL ){
   ptr =ptr->next ;
}
struct node * temp = add_at_empty(d,weight )  ;
temp->next =NULL;
ptr->next =temp ;
return head;

}


};

int check(struct node * head ,int weight ){
if(head==NULL){
    return 0;
}
struct node *ptr = head ;
while(ptr !=NULL){
    if(ptr ->weight  ==weight ){
        return 1 ;
    }
    else {
        ptr = ptr->next ;
    }
}


}

void display(struct node * head ){
printf("\n");
if(head==NULL){
    printf("\n list is empty") ;
    return ;
}
else {
    struct node * ptr = head ;
    while(ptr !=NULL){
        printf("%d ",ptr->weight ) ;
                ptr =ptr->next;

    }
}

}
int main(){
ptr[0] = NULL;
ptr[0] = insert(1,23,ptr[0] ) ;
ptr[0] = insert(2,20,ptr[0] ) ;
ptr[0] = insert(6,258,ptr[0] ) ;
ptr[0] = insert(7,33,ptr[0] ) ;
ptr[1] = NULL ;
ptr[1] = insert(5,6,ptr[1]) ;
ptr[1] = insert(6,99,ptr[1]) ;
ptr[1] = insert(7,9,ptr[1]) ;
printf("%d ",check(ptr[0],23));
    return 0;
}
