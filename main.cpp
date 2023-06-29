#include <iostream>

using namespace std;
struct node {
int data ;
node * next ;
node*prev ;
};
node*get_node(int d ){
node* newnode = (node*)malloc(sizeof(node)) ;
newnode->data =d  ;
newnode->next = newnode ;
newnode->prev = newnode ;
return newnode ;
}
void add_at_beg_end(int d, node**tail,bool beg){
if(*tail==NULL){
    *tail = get_node(d) ;
}
else{
    node*newnode=  get_node(d) ;
    newnode->next =(*tail)->next ;
    newnode->prev = (*tail) ;
    (*tail)->next->prev= newnode ;
    (*tail)->next = newnode ;
    (*tail)=beg?(*tail):newnode;
}
}
int list_size(node*tail){
int counter = 0;
if(tail==NULL){
    return counter;
}
node *ptr = tail->next ;
do{
    counter++;
    ptr =ptr->next;
}while(ptr!=tail->next);
return counter ;
}
void add_at_pos(int pos , int d , node**tail){
int n=  list_size(*tail);
if(pos<0||pos>n){
    cout<<"\nInvalid";
    return ;
}
else {
    if(pos==0){
        add_at_beg_end(d,tail,1) ;
    }
    else if(pos==n) {
        add_at_beg_end(d,tail,0) ;
    }
    else {
        node*newnode = get_node(d) ;
        node * ptr = (*tail)->next ;
        while(pos>1){
            pos--;
            ptr = ptr->next;
        }
        newnode->next= ptr->next ;
        newnode->prev = ptr ;
        ptr->next->prev = newnode ;
        ptr->prev->next = newnode ;
    }
}
}
void showlist(node*tail){
if(tail==NULL){
    return  ;
}
else {
    node*ptr = tail->next ;
    cout<<endl;
    do{
        cout<<ptr->data<<" " ;
        ptr = ptr->next ;
    }while(ptr!=tail->next) ;
}
}
void dellast(node**tail){
if(*tail==NULL){
    return ;
}
else if((*tail)->next ==*tail&&(*tail)->prev==*tail){
    free(*tail) ; (*tail) =NULL ;
}
else{
    (*tail)->prev->next =(*tail)->next;
    (*tail)->next->prev=(*tail)->prev ;
    node*temp = (*tail);
    *tail= (*tail)->prev ;
    free(temp) ; temp= NULL;
}
}
void delfirst(node**tail){
if(*tail==NULL){
    return ;
}
else if((*tail)->next ==*tail&&(*tail)->prev==*tail){
    free(*tail) ; (*tail) =NULL ;
}
else {
    node*temp = (*tail)->next ;
    temp->next->prev=(*tail) ;
    (*tail)->next  = temp->next;
    free(temp);temp = NULL;
}
}
void del_pos(int pos , node**tail){
int n=  list_size(*tail);
if(pos<0||pos>=n){
    cout<<"\nInvalid";
    return ;
}
else {
    if(pos==0){
       delfirst(tail) ;
    }
    else if(pos==n-1) {
        dellast(tail) ;
    }
    else {
        node * ptr = (*tail)->next ;
        while(pos>0){
            pos--;
            ptr = ptr->next;
        }
        ptr->next->prev=ptr->prev;
        ptr->prev->next = ptr->next ;
        free(ptr) ; ptr = NULL ;

    }
}

}
node*rev_list(node*tail){
int n= list_size(tail) ;
if(n<2){
    return tail ;
}
else {
    node*p =tail->next ;
    for(int i= 0 ; i <n; i++){
        p->prev=p->next ;
        p->next = tail ;
        tail= p ;
        p  = p->prev;
    }
tail = p;

}
return tail ;


}



int main()
{
node*tail = NULL ;
for(int i =0;  i<10;i++){
    add_at_pos(i,i+1,&tail);
}
showlist(tail) ;
tail= rev_list(tail);
showlist(tail) ;


    return 0;
}
