#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
   
        Node(int v){
        val=v;
        left=right=nullptr;
        }
};

Node* insert(Node* root,int key){
    if(root==nullptr){
        return new Node(key);
    }

    if(key<root->val){
        root->left=insert(root->left,key);
    }

    else{
        root->right=insert(root->right,key);
    } 

    return root;
}

bool search(Node* root,int key){
    if(root==nullptr){
        return false;
    }

    if(root->val==key) return true;

    if(root->val>key){
        return search(root->left,key);
    }
    return search(root->right,key);
}

int main(){
    Node* root=new Node(50);
    insert(root,60);
    insert(root,30);
    insert(root,55);
    insert(root,35);

    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;
    cout<<root->left->right->val<<endl;
    cout<<root->right->left->val<<endl;
    return 0;

}