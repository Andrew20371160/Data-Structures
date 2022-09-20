#include <iostream>
#include<queue>
using namespace std;
class node {
int data  ;
 node * right ;
 node * left ;
public:
    node(int d ){

    data = d ;
    right = NULL ;
    left =NULL;
    }
    node (){
    right = NULL;
    left = NULL;
    }
node * get_node(int d ){
node * root = NULL;
root = new node ;
root ->data = d ;
 root ->right = NULL;
 root ->left = NULL;
 return root ;
}
node * add(int d, struct node * root  ){
if(root ==NULL){
    root =get_node(d) ;
}
else if (d<root->data){
    root->left = add(d,root->left) ;
}
else {
    root->right = add(d,root->right) ;
}

return root ;

}
bool search_node(int d ,node * root ){
if(root ==NULL){
    return false   ;
}

else if(d==root->data){
    return true ;
}
else if (d <root ->data) {
    return search_node(d,root->left) ;
}
else {
    return search_node(d,root->right) ;
}
}
void display(node *root){
if(root ==NULL){
    return ;
}
queue<node*>q ;
q.push(root) ;
while(!q.empty()){
node * current = q.front() ;
cout<<current->data<<" , ";
if(current->left!=NULL) q.push(current->left) ;
if(current->right!=NULL ) q.push(current->right);
q.pop()  ;
}


}

};



int main()
{
node * root = NULL;
root =root->add(1,root) ;
root = root->add(55,root) ;
root = root->add(22,root) ;
root = root->add(-3,root) ;
root->display(root) ;
    return 0;
}
