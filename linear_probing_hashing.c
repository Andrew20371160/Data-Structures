#include <stdio.h>
#include <stdlib.h>
#define hash_size 10
int arr[hash_size] = {NULL} ;
int hash(int x){
return x%hash_size ;
}

void insert(int x){
int index  ;
for(int i = 0 ; i <hash_size ;i++){
    index = (hash(x)+i)%hash_size ;
    if(arr[index]==NULL){
        arr[index] = x;
        break;
    }
    if(index >=hash_size){
        printf("\n full ") ;
        return ;
    }
}

}




int main()
{
insert(7);
insert(9);
insert(33);
insert(66) ;

for(int i= 0 ; i<hash_size ; i++){
    printf("%d ",arr[i]);
}
    return 0;
}
