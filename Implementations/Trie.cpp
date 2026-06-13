#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
};

class Trie{
    public:

        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }

        void insert(string word){
            TrieNode* temp=root;
            for(char c:word){
                int index=c-'a';
                if(!temp->children[index]){
                    temp->children[index]=new TrieNode();
                }
                temp=temp->children[index];
            }
            temp->isEnd=true;
        }

        bool search(string word){
            TrieNode* temp=root;
            for(char c:word){
                int index=c-'a';
                if(!temp->children[index]){
                    return false;
                }
                temp=temp->children[index];
            }
            return temp->isEnd;
        }

         bool startsWith(string word){
            TrieNode* temp=root;
            for(char c:word){
                int index=c-'a';
                if(!temp->children[index]){
                    return false;
                }
                temp=temp->children[index];
            }
            return true; 
        }

        void deleteWord(string word){
            TrieNode* temp=root;
            for(char c:word){
                int index=c-'a';
                if(!temp->children[index]){
                    return;
                }
                temp=temp->children[index];
            }
            if(temp->isEnd==true){
                temp->isEnd=false;
            }
        }

          void print(TrieNode* temp, string prefix) const
    {
        if (temp->isEnd) {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (temp->children[i]) {
                print(temp->children[i],
                      prefix + char('a' + i));
            }
        }
    }

        void print() const { print(root, ""); }

};
int main(){
    Trie trie;
    trie.insert("geek");
    trie.insert("geeks");
    trie.insert("code");
    trie.insert("coder");
    trie.insert("coding");

   
    cout << "Trie contents:" << endl;
    trie.print();

   
    cout << "\nSearch results:" << endl;
    cout << "geek: " << trie.search("geek") << endl;
    cout << "geeks: " << trie.search("geeks") << endl;
    cout << "code: " << trie.search("code") << endl;
    cout << "coder: " << trie.search("coder") << endl;
    cout << "coding: " << trie.search("coding") << endl;
    cout << "codex: " << trie.search("codex") << endl;

   
    cout << "\nPrefix results:" << endl;
    cout << "ge: " << trie.startsWith("ge") << endl;
    cout << "cod: " << trie.startsWith("cod") << endl;
    cout << "coz: " << trie.startsWith("coz") << endl;

    
    trie.deleteWord("coding");
    trie.deleteWord("geek");

   
    cout << "\nTrie contents after deletions:" << endl;
    trie.print();

    
    cout << "\nSearch results after deletions:" << endl;
    cout << "coding: " << trie.search("coding") << endl;
    cout << "geek: " << trie.search("geek") << endl;
    return 0;
}