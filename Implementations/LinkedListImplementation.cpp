#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

class Node{
    public: 
    int value;
    Node* next;
    
    Node(int v){
        value=v;
        next=nullptr;
    }
};

class LinkedList{
    public: 
   Node* head; 
   
   LinkedList(){
       head=nullptr;
   }
   
   void insertAtEnd(int value){
       Node* nodeToInsert=new Node(value);
       
       if(head==nullptr){
           head=nodeToInsert;
           return; 
       }
       
       Node* temp=head;
       while(temp->next!=nullptr){
           temp=temp->next;
       }
       
       temp->next=nodeToInsert;
       
       return; 
   }
   
   void insertAtHead(int value){
       Node* nodeToInsert=new Node(value);
       
       if(head==nullptr){
           head=nodeToInsert;
           return; 
       }
       
       nodeToInsert->next=head;
       head=nodeToInsert; 
       return; 
   }
   
   void deleteVal(int val){
        if(head==nullptr) return; 
        
        if(head->value==val){
            Node* temp=head;
            head=head->next;
            delete temp;
            return; 
        }
        
        Node* curr=head;
        while(curr->next && curr->next->value!=val) curr=curr->next;
        if(curr->next){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp; 
            return; 
        }
       
       
   }
   
   void printList(){
       if(head==nullptr) return;
       Node* temp=head;
       while(temp!=nullptr){
           cout<<temp->value<<" ";
           temp=temp->next;
       }
       cout<<endl; 
   }
   
};

int main() {
   
    LinkedList* ll=new LinkedList();
    ll->insertAtEnd(3);
    ll->insertAtEnd(5);
    ll->insertAtEnd(7);
    ll->insertAtHead(9);
    ll->insertAtHead(-11);
    ll->insertAtHead(9);
    ll->deleteVal(9);
    ll->printList();
    return 0;
}