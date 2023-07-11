#include <stdio.h>
#include <stdlib.h>
#define max 10
//our queue
int q_arr[max];
int rear=-1,front =-1;

int is_empty(){
return (rear==-1)&&(front==-1);
}

int is_full(){
return (rear+1)%max==front;
}

void enque(int d ){
if(is_full()){
    return;
}
else if(is_empty()){
    rear=0; front=0;
}
rear=(rear+1)%max;
q_arr[rear] = d;
}

int deque(){
if(is_empty()){
    printf("\nEmpty Queue");
    return -1 ;
}
else if(rear==front){
    rear=-1 ; front =-1 ;
}
else{
int num= q_arr[front] ;
front = (front+1)%max;
return num ;
}
}

void show(){
if(is_empty()){
    return ;
}
puts("");
int i = front  ;
while(i!=rear){
    printf("%d ",q_arr[i]);
    i=(i+1)%max;

}
printf("%d",q_arr[rear]);
}
int main(){
for(int i = 0 ; i <10;i++){
    enque(i+1);
}

show();
deque();
deque();
show();
deque();
deque();
deque();
enque(69);
show();
deque();
deque();
deque();
show();

    return 0;
}
