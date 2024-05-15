#include <bits/stdc++.h> 
struct Node{
    Node *Next[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containKye(char ch){
        return Next[ch - 'a'] != NULL;
    }
    void put(char ch, Node *newNode){
        Next[ch - 'a'] = newNode;
    }
    Node *get(char ch){
        return Next[ch - 'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    void reduceEnd(){
        cntEndWith--;
    }
};
class Trie{

    private:
    Node *root;

    public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++){
            if(!temp -> containKye(word[i])){
                temp->put(word[i], new Node());
            }
            //moves to the referacne trie
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node *temp = root;
        for(int i = 0; i < word.size(); i++){
            if(!temp->containKye(word[i])){
                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node *temp = root;
        for(int i = 0; i < word.size(); i++){
            if(!temp->containKye(word[i])){
                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->cntPrefix;
    }

    void erase(string &word){
        Node *temp = root;
        for(int i = 0; i < word.size(); i++){
            temp = temp->get(word[i]);
            temp->reducePrefix();
        }
        temp->reduceEnd();
    }
};
