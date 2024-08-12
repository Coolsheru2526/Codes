#include<stack>
#include <iostream>
#include <vector>
#include <stack>

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



vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);  // Initialize NGE with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            nge[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return nge;
}
vector<int> previousGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n, -1);  // Initialize PGE with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pge[i] = st.top();
        }
        st.push(nums[i]);
    }

    return pge;
}

vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, -1);  // Initialize NSE with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            nse[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return nse;
}

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);  // Initialize PSE with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(nums[i]);
    }

    return pse;
}