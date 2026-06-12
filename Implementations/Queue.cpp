#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int front;
    int rear;
    int arr[1000];
    Queue(){
        front=rear=-1; 
    }
    
    void push(int v){
        if(front==-1) front++;
        arr[++rear]=v;
    }
    
    void pop(){
        if(front==-1) return; 
        else if(front==rear)  front=rear=-1;
        else{
             front++;
        }
    }
    
    int peak(){
        if(front==-1) return -1; 
        return arr[front];
    }
    bool empty(){
        return front==-1; 
    }
    
};

int main(){
   
    Queue q;
    q.push(3);
    q.push(4);
    q.push(7);
    q.push(27);
    cout<<q.peak()<<endl; 
    q.pop();
    cout<<q.peak()<<endl; 
    q.pop();
    cout<<q.peak()<<endl; 
    q.pop();
    cout<<q.peak()<<endl; 
    q.pop();
    cout<<q.peak()<<endl; 
    
    
    return 0;
}