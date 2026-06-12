#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
        int* arr;
        int front;
        int rear;
        int size;

        CircularQueue(int s){
            front=rear=-1;
            size=s;
            arr=new int[size];
        }

        bool isEmpty(){
            return front==-1;
        }

        bool isFull(){
            return (rear+1)%size==front;
        }

        void push(int v){
            if(isFull()){
                return; 
            }

            if(front==-1){
                front=(front+1)%size;
            }

            rear=(rear+1)%size;
            arr[rear]=v;
        }

        void pop(){
            if(isEmpty()){
                return;
            }

            if(front==rear){
                front=rear=-1;
                return; 
            }

            front=(front+1)%size;
        }

        int seek(){
            if(isEmpty()) return -1;
            return arr[front];
        }

};

int main(){
    CircularQueue cq(3);

    cq.push(3);
    cq.push(2);
    cq.push(10);
    cq.pop();
    cq.push(11);
    cout<<cq.seek()<<endl;
    cq.pop();
    cout<<cq.seek()<<endl;
    cq.pop();
    cout<<cq.seek()<<endl;
    cq.pop();
    
    
    return 0; 
}