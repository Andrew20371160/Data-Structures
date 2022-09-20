#include<stdlib.h>
#include<stdio.h>
struct node {
int data ;
struct node * next ;
};
int isempty(struct node * top ){
return(top==NULL) ;
}

struct node * add_at_empty(int d){
struct node * top =  malloc(sizeof(struct node));
top->data  =d  ;
top->next = NULL ;
return top  ;
};
struct node *push(int d, struct node * top ){
if(isempty(top)){
    top = add_at_empty(d) ;
    return top ;
}

struct node * temp = add_at_empty(d) ;
temp->next = top ;
top = temp ;
return top ;
};

int pop(struct node ** top ){

if(isempty(*top)){
    printf("\n list is empty ") ;
    return -1 ;
}
else if(&(*top)->next == NULL){
    int d = (*top)->data ;
    free(*top) ;
    *top = NULL;
    return d ;
}
else {
int data = (*top)->data ;
struct node  *temp= *top ;
(*top) =(*top)->next ;
free(temp) ;
(temp) = NULL ;
return data ;
}

}
void show(struct node * top ){
if(isempty(top)){
    printf("\n list is empty");
    return ;
}
struct node *ptr = top  ;
printf("\n ");
while(ptr!=NULL){
    printf("%d ",ptr->data );
    ptr = ptr->next  ;
}

}
struct node * del_list (struct node * top ){

if(isempty(top)){
    printf("\n list is empty ") ;
    return top ;
}
else if(top->next == NULL ){
    free(top ) ;
    top = NULL;
    return top ;

}
struct node * temp= top ;
while(top!=NULL){
    temp =top;
    top =top->next ;
    free(temp) ;
}
top = NULL;
return top ;
};
struct node * reverse_stack(struct node * top ){
if(isempty(top) || top->next ==NULL){
    printf("\n can't reverse a stack that has zero or one element ") ;
    return top ;
}
struct node*rev_st = NULL ;
while(top){
    rev_st = push(pop(&top),rev_st) ;
}


return rev_st;
};


struct node * create(struct node * top ){
int answer  ;

while(1){
printf("\n 1.insert a node ") ;
printf("\n 2.pop top node ") ;
printf("\n 3.show list  ") ;
printf("\n 4.delete the list  ") ;
printf("\n 5.reverse stack ");
printf("\n 6.quit \n ") ;
scanf("%d",&answer) ;
switch(answer){
case 1 : printf("\n enter data :") ; int data ; scanf("%d",&data) ;top =push(data,top) ; break ;
case 2 : {int d = pop(&top) ; printf("\n %d ",d);break ;}
case 3 : show(top) ; break ;
case 4 : top = del_list(top) ;  break ;
case 5 : top = reverse_stack(top); break ;
case 6 : exit(0) ; break ;

default : printf("wrong answer ") ;


}
}



};

int main(){
struct node * stack = NULL ;
stack = create(stack) ;




return  0;
}
