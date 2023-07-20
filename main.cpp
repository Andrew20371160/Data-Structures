#include <iostream>

using namespace std;
struct node{
int data ;
node*left ;
node*right ;
};
class bst{
private:
node*root ;
public:
    bst(){root =NULL;}
    node*getnode(int d);
    void insert_data(int data);
    void display(node *leaf){
    if(leaf==NULL){
        return ;
    }
    else{
        display(leaf->left);
        cout<<leaf->data<<" ";
        display(leaf->right) ;
    }

    }
    void displaybyuser(){
    display(root);
    }
    node *insert_d(int data ,node*leaf){
    if(leaf==NULL){
        leaf = getnode(data);
        return leaf ;
    }
    else if(data >leaf->data){
        leaf->right = insert_d(data,leaf->right) ;
    }
    else{
        leaf->left = insert_d(data,leaf->left);
    }
    }
};
node* bst::getnode(int d){
node*newnode = (node*)malloc(sizeof(node));
newnode->left = NULL;
newnode->right = NULL;
newnode->data = d ;
return newnode ;
}
void bst::insert_data(int data){
root = insert_d(data,root) ;
}

int main()
{
bst tree ;
tree.insert_data(1);
tree.insert_data(14);
tree.insert_data(7);
tree.insert_data(3);
tree.insert_data(42);
tree.displaybyuser();
    return 0;
}
