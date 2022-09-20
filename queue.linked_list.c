#include<stdio.h>
#include<stdlib.h>
struct node {
int data ;
struct node * next  ;
};
int isempty(struct node * tail ) {
return(tail==NULL) ;
}
struct node * add_at_empty(int d){
struct node * tail =malloc(sizeof(struct node ))  ;
tail->data= d ;
tail->next = tail  ;
return tail  ;
};
struct node * add_at_end(int d , struct node * tail ){
if(isempty(tail)){
    tail = add_at_empty(d)  ;
    return tail ;
}
else if(tail->next ==tail ){
struct node * temp= add_at_empty(d) ;
temp->next = tail  ;
tail->next= temp ;
tail  = temp ;
return tail  ;
}
else {
struct node * temp= add_at_empty(d);
temp->next = tail->next ;
tail->next = temp ;
tail = temp ;
return tail ;
}

};
int dequeue(struct node **tail ){
if(isempty(*tail)){
    printf("\n queue is empty");
    return -1 ;
}
else if((*tail)->next  == (*tail)){
    int val = (*tail)->data;
    free((*tail)) ;
    (*tail) = NULL ;
    return val ;
}
else {
struct node * temp = (*tail)->next ;
int val = temp->data  ;
(*tail)->next = temp->next ;
free(temp) ;
return val  ;

}

}
int peek(struct node * tail){
if(isempty(tail)){
    printf("\n queue is empty ") ;
    return -1 ;
}
else if (tail->next ==tail ){
    return (tail->data)  ;
}

return tail->next ->data ;
}
void display(struct node * tail ){
printf("\n" );
if(isempty(tail)){
    printf("\n queue is empty") ;
    return ;
}
else if (tail->next == tail ){
    printf("\n %d",tail->data) ;
    return ;
}
else {
struct node * ptr = tail->next ;
do{
printf(" %d",ptr ->data) ;
ptr = ptr ->next ;

}while(ptr !=tail->next);
}
}

int main(){
struct node * tail = NULL ;
tail = add_at_empty(1) ;
tail=add_at_end(7,tail) ;
tail=add_at_end(66,tail) ;
tail=add_at_end(5,tail) ;
display(tail) ;
int n = dequeue(&tail) ;
printf("\n  %d",peek(tail)) ;
display(tail );
return 0 ;
}
