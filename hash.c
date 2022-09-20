#include<stdio.h>
#include<stdlib.h>
#define max 7
struct node{
int data ;
struct node * next ;
};* head[max];

struct node * add_at_empty(int d ) {
struct node * head = malloc(sizeof(struct node));
head->data = d;
head->next = NULL ;
return head ;

};
struct node * add_at_end(int d ,struct node * head){
if(head ==NULL){

    head= add_at_empty(d)  ;
     return head;
}
else if (head->next ==NULL){
    struct node * temp = add_at_empty(d) ;
    temp->next = NULL ;
    head->next = temp  ;
    return head ;
}
else {
    struct node * temp = add_at_empty(d) ;
struct node * ptr = head;
while(ptr ->next !=NULL){
ptr = ptr->next ;

}
temp->next= NULL ;
ptr ->next  =temp ;
return head;
}


};
void show(struct node * head){
if(head ==NULL){
    printf("\n empty ") ;
    return ;
}
else {
    struct node * ptr = head;
    while(ptr!=NULL){


        printf("%d ",ptr->data)  ;
        ptr  =ptr->next ;

    }

}
}
int isempty(struct node *head){

return(head==NULL) ;
}

void hash(int d){
int index = d%max ;
if(isempty(head[index])){
    head[index] = add_at_empty(d)  ;
}
else {
head[index] = add_at_end(d,head[index]) ;

}

}
int find_index(int data ){

if(data%max>=max){
    printf("\n position doesn't exist ") ;
    return -1 ;
}

if(isempty(head[data%max])){
    printf("\n data not found ") ;
    return -1 ;
}
else {
    return data%max ;
}

}

int find_int(int index ){

printf("\n");
if(index >=max){
    printf("\n position doesn't exist ") ;
    return -1 ;
}
else if(isempty(head[index])){
    printf("\n empty ") ;
    return -1 ;
}
else {
struct node * ptr = head[index]  ;

 if (ptr ->next !=NULL){
    show(ptr);
    return 0 ;

 }


else {
return (ptr->data) ;
}

}

}

int main(){
for(int i = 0; i <10 ;i++){
    hash(i);
}
for(int i = 0 ; i <max ;i++){
printf("\n row number %d :",i);
    show(head[i]) ;
}


int n= find_int(1);
printf("\n %d",n);
return 0;
}
