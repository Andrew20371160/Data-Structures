#include<stdio.h>
#include<stdlib.h>
#define max 10
int head = -1 ;
int tail = -1 ;
int arr[max];

int isempty(){
return (head ==-1 && tail == -1 );
}
void enqueue(int data){

if(isempty()){
tail++ ;
head++ ;
arr[tail] = data ;
}
else if((tail+1)%max == head){
    printf("\n queue is empty") ;
    return ;
}
else {
tail = (tail+1)%max ;
arr[tail]  = data ;
}

}
int dequeue(){
if(isempty()){
    printf("\n queue is empty ") ;
    return -1 ;
}
else if (head ==tail ){
head = -1  ;
tail = -1 ;

return -1 ;
}
head =(head +1)%max ;
return(arr[head]);

}
void display(){
if(isempty()){
    printf("\n queue is empty") ;
    return  ;
}
for (int i = head; i <=tail ; i++){
    printf("%d , ",arr[i]);
}
}
int main(){

enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
dequeue();
dequeue();
dequeue();
dequeue();

display();
return 0 ;
}
