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
    stack1 s1;
cout<<"enter the array ";
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.push(5);
s1.push(6);
s1.push(7);
s1.push(8);
s1.push(9);
s1.push(10);
for(int  i = 0 ; i<10 ; i++)
    cout<<s1.pop()<<" " ;







    return 0;
}
