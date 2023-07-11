#include<stdio.h>
#include<stdlib.h>
#define max 40
int front = -1 ;
int rear = -1 ;
int arr[max];

int is_empty(){
return (front ==-1 && rear == -1 );
}
int is_full(){
return (rear+1)%max==front ; 
}
void enque(int data){
if(is_empty()){
front = 0 ; rear = 0;
arr[rear] = data ;
}
else if(is_full(){
    printf("\nFull Queue") ;
    return ;
}
else {
rear =(rear+1)%max ; 
arr[rear]  = data ;
}
}
int deque(){
if(is_empty()){
    printf("\nEmpty queue") ;
    return -1 ;
}
else if (rear ==front ){
rear = -1  ;
front = -1 ;
}
else{
front =(front +1)%max ;
return(arr[head]);
}
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
