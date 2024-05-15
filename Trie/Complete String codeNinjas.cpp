#include <bits/stdc++.h> 
struct Node{
    Node *Next[26];
    bool End;
    bool containKye(char ch){
        return Next[ch - 'a'] != NULL;
    }
    void put(char ch, Node *newNode){
        Next[ch - 'a'] = newNode;
    }
    Node *get(char ch){
        return Next[ch - 'a'];
    }
    void setEnd(){
        End = true;
    }
};


class Trie {
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
        }
        temp ->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++){
            if(!temp -> containKye(word[i])){
                return false;
            }
            temp = temp -> get(word[i]);
        }
        return temp -> End;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!temp -> containKye(prefix[i])){
                return false;
            }
            temp = temp -> get(prefix[i]);
        }
        return true;
    }
};

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

string completeString(int n, vector<string> &a){
    Trie T;
    sort(a.begin(), a.end(), cmp);
    string ans = "None";
    for(int i = 0; i < n; i++){
        T.insert(a[i]);
        //cout << a[i] << endl;
    }
    for(int i = 0; i < n; i++){
        if(ans != "None" and ans.size() == a[i].size())continue;
        string xx = "";
        bool ok = true;
        for(auto x: a[i]){
            xx += x;
            //cout << xx << endl;
            if(!T.search(xx)){
                ok = false;
                break;
            }
        }
        if(ok) ans = xx;
    }
    return ans;
}
