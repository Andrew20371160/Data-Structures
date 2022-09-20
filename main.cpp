#include <iostream>

using namespace std;
class stack1{
private:
    enum {MAX =10 };
    int top;
    int st[MAX];
public:
    stack1(){
    top = -1 ;
    }
    bool isempty(){
    if(top ==-1){
        return true;}
    return false ;

    }
    bool isfull(){
    if(top == MAX -1){
        return true ;

    }
    else
    return false ;
    }

    void push(int var){
    if(!isfull())
    st[++top] = var ;
    else
        cout<<"over flow "<<endl;

    }
    int pop (){
        if(!isempty()){
        cout<<endl;
     return st[top--];
    }
    else
       {

        cout<<"underflow "<<endl;
        return -1 ;
       }
    }

};
int main()
{







    return 0;
}
