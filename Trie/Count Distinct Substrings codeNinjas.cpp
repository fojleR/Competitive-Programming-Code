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
    int insert(string word, int st) {
        Node *temp = root;
        int cnt = 0;
        for(int i = st; i < word.size(); i++){
            if(!temp -> containKye(word[i])){
                temp->put(word[i], new Node());
                cnt++;
            }
            //moves to the referacne trie
            temp = temp->get(word[i]);
        }
        temp ->setEnd();
        return cnt;
    }
};
int countDistinctSubstrings(string &s){
    Trie T;
    int ans = 1;
    for(int i = 0; i < s.size(); i++){
        ans += T.insert(s, i);
    }
    return ans;
}