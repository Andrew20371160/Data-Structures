#include <stdio.h>
#include <stdlib.h>
#define hash_table 10
int arr[hash_table] = {NULL} ;
int hash(int x ){
return x%hash_table ;
}
void insert(int x){
int index;
for(int i= 0 ; i <hash_table ;i++  ){
index = (hash(x)+i*i)%hash_table ;
if(arr[index]==NULL){
    arr[index]  = x;
    break ;
}
if(index >=hash_table){
    printf("\n full ");

}
}
}

int main()
{
insert(7) ;
insert(22) ;
insert(33) ;
insert(936) ;
for(int i = 0 ; i <hash_table; i++) {
    printf(" %d ",arr[i]) ;
}

    return 0;
}
