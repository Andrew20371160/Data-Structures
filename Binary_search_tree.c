#include <stdio.h>
#include <stdlib.h>
//node struct
typedef struct node{
int data ;
struct node * left ;
struct node * right ;
}node ;
//get memory for a new node
node *get_node(int d ){
node * newp= malloc(sizeof(node));
newp->data = d ;
newp->left = NULL ;
newp->right = NULL ;
return newp;
}
//insertion function (recursion version)
void insert(int d ,node**root){
if(*root ==NULL){
    (*root)=  get_node(d) ;
}
else if(d<=(*root)->data){
    insert(d,&((*root)->left)) ;
}
else{
     insert(d,&((*root)->right)) ;
}
}
//insertion function using iteration (better for low systems memory)
void insert_iter(int d ,node**root){
if(*root==NULL){
    *root=get_node(d);
}
else{
node * ptr=*root ;
while(1){
    if(d<=ptr->data&&ptr->left!=NULL){
        ptr=ptr->left;
    }
    else if(d>ptr->data&&ptr->right!=NULL){
        ptr =ptr->right;
    }
    else if(d<=ptr->data&&ptr->left==NULL){
        ptr->left=get_node(d);
        break;
    }
    else{
        ptr->right=get_node(d);
        break;
    }
}
}
}
//Search function
int search(int d  , node *root){
if(root==NULL){
    return 0 ;
}
else if(d==root->data){
    return 1 ;
}
else if(d<root->data){
    return search(d,root->left);
}
else{
    return search(d,root->right) ;
}
}
//Preorder traversal(DLR)
//Midorder traversal(LDR)
//Inorder traversal(LRD)
//display function
void inorder(node*root){
if(root==NULL){
    return  ;
}
else{
    inorder(root->left) ;
    printf("%d ",root->data) ;
    inorder(root->right) ;
}
}

//Height of a BST
int height(node * root){
if(root==NULL){
    return -1 ;
}
int hl = height(root->left)+1 ;
int hr = height(root->right) +1;
return (hl>hr)?hl:hr;
}

//returns a pointer to maximum data of a BST
//Used in del_node
node *get_max_iter(node *root){
if(root==NULL){
    return root  ;
}
else{
    while(root->right!=NULL){
        root = root->right ;
    }
}
return root;
}
//same previous function using recursion
node *get_max(node *root ){
if(root==NULL){
    return root  ;
}
else if(root->right==NULL){
    return root ;
}
else{
    return get_max(root->right) ;
}
}
//Delete a node function
node *del_node(int d , node *root){
if(root==NULL){
    return root ;
}
else if(d<root->data){
    root->left = del_node(d,root->left) ;
}
else if(d>root->data){
    root->right =del_node(d,root->right) ;
}
else{
if(root->left==NULL&&root->right==NULL) {
    free(root) ; root = NULL;
}
else if(root->left==NULL){
node *temp = root ;
root= root->right ;
free(temp) ; temp =NULL ;
}
else if(root->right==NULL){
node*temp = root ;
root= root->left ;
free(temp) ; temp = NULL;
}
else  {
node *temp = get_max(root->left) ;
root->data=temp->data ;
root->left= del_node(temp->data,root->left) ;
}
return root  ;
}
return root  ;
}
//delete the whole BST
node*del_all(node*root){
if(root==NULL){
    return root ;
}
return del_all(root->left);
free(root); root =NULL;
return del_all(root->right);
}
//Is the tree a BST ?
//first you use (tree_to_arr) (traverse the elements into an array)
//then you use (is_bst)(easily check the prev and next elements)
int is_bst(int * arr, int size){
for(int i = 0 ; i<size;i++){
    if(arr[i]>arr[i+1]){
        free(arr) ;arr=NULL ;
        return 0;
    }
}
//Dynamically allocated array with same size of number of elements of the Tree
//don't forget to deallocate it
free(arr); arr= NULL;
return 1 ;
}
//For the next function
int i = 0 ;
int * arr =NULL;
void tree_to_arr(node * root){
if(root==NULL){
    return ;
}
tree_to_arr(root->left) ;
arr = (int*)realloc(arr,sizeof(int)*(i+1));
*(arr+i)=root->data  ;
i++;
tree_to_arr(root->right);
}
//get address of a node by data
node*get_address(int d , node *root){
if(root==NULL){
    return root ;
}
else if(d==root->data){
    return root ;
}
else if(d<root->data){
    return get_address(d,root->left) ;
}
else{
    return get_address(d,root->right) ;
}
}
//inorder successor O(n)
void inorder_succ_trav(int d ,node *root){
if(root==NULL){
    return ;
}
//to check if we visited the wanted data
static int flag = 0 ;
inorder_succ_trav(d,root->left);
if(flag){
printf("\n%d",root->data);
flag = 0;
//The next statement ends recursion
//hence no need to check for rest of the nodes (more efficient when dealing with big data)
inorder_succ_trav(d,NULL);
}
//This has to be second statement if its first statement
//You will print the same data not the successor
if(d==root->data){
    flag =1;
}
inorder_succ_trav(d,root->right) ;
}
//this reduces search area by half still O(n)
void inorder_successor(int d,node*root){
if(root==NULL){
    return ;
}
else if(d<=root->data){
    inorder_succ_trav(d,root);
}
else{
    inorder_succ_trav(d,root->right);
}
}
int main()
{
node *root = NULL;
insert_iter(15,&root);
insert_iter(10,&root);
insert_iter(8,&root);
insert_iter(6,&root);
insert_iter(12,&root);
insert_iter(11,&root);
insert_iter(20,&root);
insert_iter(17,&root);
insert_iter(16,&root);
insert_iter(25,&root);
insert_iter(27,&root);
inorder(root);
inorder_successor(6,root);
inorder_successor(8,root);
inorder_successor(10,root);
inorder_successor(11,root);
inorder_successor(12,root);
inorder_successor(15,root);
inorder_successor(16,root);
inorder_successor(17,root);
inorder_successor(20,root);
inorder_successor(25,root);
inorder_successor(27,root);
    return 0;
}
