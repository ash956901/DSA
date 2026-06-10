#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *prev;
    Node *next;

    Node(int v){
        value=v;
        prev=nullptr;
        next=nullptr;
    }
};

class DLL{
    public:
        Node* head;
        Node* tail;

        DLL(){
            head=tail=nullptr;
        }

        void insertAtHead(int v){
            Node* temp=new Node(v);

            if(head==nullptr){
                head=tail=temp;
                return; 
            }

            temp->next=head;
            head->prev=temp; 
            head=temp;
            return; 
        }

        void insertAtTail(int v){
            Node* temp=new Node(v);

            if(head==nullptr){
                head=tail=temp;
                return; 
            }

            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            return;
        }

        void deleteVal(int v){
            Node* temp=head;

            while(temp!=nullptr && temp->value!=v){
                temp=temp->next;
            }
            
            if(!temp) return;
            
            if(temp==head){
                head=head->next;
                if(head) head->prev=nullptr;
                else tail=nullptr;
            }
            else if(temp==tail){
                tail=tail->prev;
                tail->next=nullptr;
            }
            else{
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next; 
            }
            delete temp; 
            }

        

        void printList(){
            if(head==nullptr) return; 
            Node* curr=head;
            while(curr!=nullptr){
                cout<<curr->value<<" ";
                curr=curr->next;
            }
        }
};



int main(){
    DLL *dll=new DLL();
    dll->insertAtHead(1);
    dll->insertAtHead(2);
    dll->insertAtHead(10);
    dll->insertAtTail(-5);
    dll->insertAtTail(-2);
    dll->deleteVal(10);
    dll->printList();

    return 0;
}