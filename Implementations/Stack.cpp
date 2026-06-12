#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{
   
    int arr[10000];
    int topIndex;
public:
    Stack(){
        topIndex=-1;
    }
    
    void push(int val){
        arr[++topIndex]=val;
    }
    
    void pop(){
        if(topIndex>=0){
             topIndex--;
        }
       
    }
    
    int top(){
        if(topIndex>=0){
             return arr[topIndex];
        }
        return -1;
    }
    
    bool empty(){
        return topIndex==-1;
    }
};
int main(){
   
    Stack st;
    st.push(3);
    st.push(4);
    cout<<st.top();
    st.pop();
    cout<<st.top();
    
    return 0;
}