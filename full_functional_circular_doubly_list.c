#include<stdlib.h>
#include<stdio.h>
struct node {
int data ;
struct node * next  ;
struct node * prev ;
};
struct node * add_at_empty (int d ){
struct node * tail   = malloc(sizeof(struct node )) ;
tail->data = d ;
tail->next = tail ;
tail->prev = tail  ;
return tail ;
};
struct node * add_at_beg(int d ,struct node * tail ){
struct node * temp = add_at_empty(d) ;
temp->next = tail ->next  ;
temp->prev = tail ;
tail->next->prev = temp  ;
tail ->next = temp   ;
return tail ;

};
struct node * add_at_end(int d ,struct node * tail ){
struct node * temp= add_at_empty(d) ;
temp ->next  =tail->next ;
temp->prev = tail  ;
tail ->next ->prev= temp ;
tail->next = temp  ;
tail = temp ;
return tail  ;


};
int list_size(struct node * tail ){
int size = 0 ;
struct node * ptr = tail->next ;
do{
    size ++ ;
    ptr = ptr ->next  ;
}while(ptr != tail ->next );

return size  ;

};
struct node * add_at_pos(int d , int pos , struct node * tail ){
if(tail ==NULL){
    printf("\n list is empty ") ;
    return tail ;
}
else if(tail ->next == tail ){
    printf("\n position doesn't exist ") ;
    return tail  ;
}
else if (pos == 1 ){
    tail = add_at_beg(d,tail ) ;
    return tail ;
}
else if(pos ==list_size(tail)+1){
    tail =add_at_end(d,tail );
    return tail ;
}
else if (pos > list_size(tail)+1){
printf("\n list is empty ") ;
return tail ;

}

else {
pos-- ;
struct node * temp=add_at_empty(d) ;
struct node * ptr = tail ->next ;
while(pos !=1){
    ptr = ptr->next   ;
    pos --  ;
}
temp->next = ptr->next ;
temp->prev = ptr ;
ptr->next->prev  =temp ;
ptr ->next  = temp ;
return tail  ;

}

};
struct node * del_1st_node (struct node * tail ){
if(tail == NULL){
    printf("\n list is empty ") ;
    return tail ;
}
else if(tail->next == tail ){
    free(tail ) ;
    tail = NULL ;
     return tail ;
}
else {
struct node * ptr = NULL;
ptr = tail->next ;
ptr ->next ->prev = tail  ;
tail->next = ptr ->next ;
free(ptr ) ;
ptr =NULL ;
return tail ;

}
};
struct node * del_last_node (struct node * tail ){
if(tail == NULL){
    printf("\n list is empty ") ;
    return tail ;
}
else if(tail->next == tail ){
    free(tail ) ;
    tail = NULL ;
     return tail ;
}
else {
    struct node * ptr  = tail->prev ;
    tail->next ->prev =  ptr ;
    ptr ->next  = tail ->next ;
    free(tail) ;
    tail = ptr ;
    return  tail ;

}

};
struct node * del_at_pos (int pos , struct node * tail ){
if(tail == NULL){
    printf("\n list is empty ") ;
    return tail ;
}
else if(tail->next == tail ){
  printf("\n  position doesn't exist  ") ;

     return tail ;
}
else if (pos == list_size(tail)){
   tail =  del_last_node(tail) ;
    return tail ;
}
else if (pos ==1 ){
    tail = del_1st_node(tail);
    return tail ;
}
else if(pos >list_size(tail) +1){
printf("\n position doesn't exist ") ;
return tail ;
}
else {
    struct node * ptr = tail->next ;
    while(pos!=1){
        ptr = ptr->next  ;
        pos-- ;
    }
ptr->prev->next = ptr ->next ;
ptr->next->prev = ptr->prev ;
free(ptr) ;
ptr = NULL ;
return tail ;


}
};
void show(struct node * tail ){
struct node * ptr = tail->next ;
printf("\n");
do{
    printf("%d ",ptr->data) ;
    ptr=ptr->next ;
}while(ptr!=tail->next);


}
int main(){
struct node * tail = add_at_empty(1) ;
tail =add_at_beg(2,tail) ;
tail =add_at_beg(2,tail) ;
tail = add_at_end(5,tail) ;
tail = add_at_end(22,tail) ;
tail =add_at_pos(7,list_size(tail)+1,tail) ;
show(tail);
tail = del_at_pos(3,tail);
show(tail) ;

return 0 ;
}
