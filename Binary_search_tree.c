#include <stdio.h>
#include <stdlib.h>
#define max 4
struct  node ;

int top = -1 ;

struct node * arr[max] ; 
void push(struct  node* d ){
    arr[++top] = d ;
}
struct  node* pop(){
    return arr[top--];
}
struct node {
int data ;
struct node * right ;
struct node * left ;
};
struct node *add_at_empty(int d ){
struct node * root = malloc(sizeof(struct node ));
root ->data = d  ;
root ->left = NULL ;
root ->right = NULL ;
return root ;
};
struct node * insert(int d , struct node * root ){
if (root ==NULL){
    root = add_at_empty(d)  ;
}
else if (d<root->data){
    root ->left = insert(d,root->left ) ;
}
else {
    root ->right = insert(d,root->right) ;
}
return root ;
};
int search(int d ,struct node * root ){
if(root ==NULL){
    return 0;
}
else if(d==root->data){
    return 1 ;
}
else if (d<root->data){
    return(search(d,root->left)) ;
}
else {
    return search(d,root->right ) ;
}

}
int min(struct node * root ){
if(root ==NULL){
    printf("\n tree is empty ") ;
    return -1;
}
else if (root ->left ==NULL){
    return root->data ;
}
else {
    return min(root->left );
}

}
int maxd(struct node * root ){
if(root ==NULL){
    printf("\n tree is empty ") ;
    return -1 ;
}
else if (root ->right ==NULL){
    return root->data;
 }
 else {
    return maxd(root->right);
 }

}
int maxnum(int n1 ,int n2 ){
return (n1>n2)?n1:n2  ;
}
int height (struct node * root ){
if(root ==NULL){
    return -1 ;
}
int lefth,righth;
lefth =height(root->left );
righth = height(root->right ) ;
return maxnum(lefth,righth) +1;

}
void preorder(struct node * root){
if(root==NULL){
    return ;
}
printf("%d ",root->data);
preorder(root->left)  ;
preorder(root->right)  ;

};
void inorder(struct node *root ){
if(root==NULL) return ;
inorder(root->left ) ;
printf("%d ",root->data) ;
inorder(root->right);


}
void postorder(struct node *root ){
if (root ==NULL){
return ;
}
inorder(root->left) ;
inorder(root->right) ;
printf("%d ",root->data );
}

//is it a binary search tree ?
void inorder_trav(struct node*root ,int *arr ){


if(root ==NULL) return  ;
inorder_trav(root->left ,arr) ;
*arr++ =root->data ;             //store in an array 
inorder_trav(root->right ,arr) ;

}
int isbst(int * arr){
for(int i = 0 ; i <sizeof(arr)/sizeof(int);i++){
    if(*(arr+i+1)<*(arr+i)){        // check if each element in the array is less that the afterward eleement 
        return 0 ;
    }
}
return 1;
}
//better approch to is binary search tree using stack 
int issmaller(int n1 , int n2 ){
return(n1<n2) ;
}
int is_bst(struct node * root ){
if(root ==NULL){
    return 1 ;
}

is_bst(root->left );
push(root->data ) ;
if(top>=1){
    if(!issmaller(pop(),pop())){
        return  0;
    }
}
is_bst(root->right);

}
//inorder sucessor using stack //remember to update it so it returns a pointer to the succsessor 
struct node * inorder_sucsesor( int d , struct node * root ){
if(root ==NULL){
    return  NULL ;
}
inorder_sucsesor(d,root->left );
push(root);
if(top>=1){
if(arr[0]->data==d){
    return arr[1] ;
}
    else if (arr[top-1]->data==d ){
        return arr[top] ;
    }

}

inorder_sucsesor(d, root->right);

}
//search func
struct node * search(int d,struct node * root ){

if(root ==NULL){
    return root  ;
}
else if (d==root->data){
    return root  ;
}
else if (d<root->data){
 return search(d,root->left);
}
else {
  return search(d,root->right) ;
}

};


//deletion func
struct node * findmin(struct node * root ){
if(root ->left  ==NULL){
    return root  ;
}
else{
   findmin(root->left ) ;
}

};
struct node * del(int d ,struct node * root ){
if(root ==NULL){
    return root ;
}
else if (d<root->data){
    root ->left = del(d,root->left ) ;
}
else if (d>root->data){
    root ->right = del(d,root->right) ;
}
else {
if(root ->left ==NULL &&root ->right==NULL){
free(root ) ;
root =NULL ;

}
else if (root ->left ==NULL){
    struct node * temp  =root ;
    root =root->right ;
free(temp ) ;
}
else if (root ->right==NULL){
    struct node * temp = root ;
    root = root ->left  ;
    free(temp) ;
}
else {
    struct node * temp = findmin(root ->right) ;
    root ->data =temp->data ;
    root ->right=del(temp->data ,root ->right);
}

}

return root ;
};






int main()
{
struct node * root = NULL ;
root = insert(1,root ) ;
root = insert(2,root ) ;
root = insert(5,root ) ;
root = insert(77,root ) ;
root = insert(-6,root ) ;
struct node * cur = inorder_sucsesor(2,root)  ;
printf("%d ",cur->data) ;
return 0;
}
