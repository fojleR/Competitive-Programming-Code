/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
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