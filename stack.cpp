#include<iostream>
#include<stack>
using namespace std;

class Stack{
     public:
        int *arr;
        int size;
        int top;
         
     Stack(int size )
     {
        this->size=size;
        this->top=-1;
         arr = new int[size];
     }
     void push(int data)
     {
        if(size-top>1)
        {
            top++;
            arr[top]=data;
        }
       else{
        cout<<"Stack Overflow"<<endl;
       }

     }
     void pop(){
       if (top>=0)
       {
        top--;
       }
       else{
        cout<<"Stack Underflow"<<endl;
       }
     }
     bool isempty(){
          if(top>=0)
          {
            return false;
          }
          else{
            return true;
          }
     }
     int peek(){
        if(top>=0 && top<size){
         return arr[top];}
         else{
           //  cout<<"stack Empty"<<endl;
             return -1;
         }
     }

};


int  main()
{


    Stack st(5);
    st.push(10);
    st.push(5);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
     cout<<st.peek()<<endl;
    if(st.isempty())
    {
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is Not Empty"<<endl;
    }
    /*
    //creation of stack
    stack<int>s;
    //pushing element in stack
    s.push(5);
    s.push(10);
    //using top() to read what is at the top
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    //poping the topmost element 
    s.pop();
    s.pop();
    //using empty function to check whether string is empty or not
    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }*/

    return 0;
}