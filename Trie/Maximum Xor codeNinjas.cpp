#define ll long long
struct Node{
    Node *Next[3];
    bool End;
    bool containKye(ll x){
        return Next[x] != NULL;
    }
    void put(ll x, Node *newNode){
        Next[x] = newNode;
    }
    Node *get(ll x){
        return Next[x];
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
    void insert(ll num) {
        Node *temp = root;
        for(long long i = 31; i >= 0; i--){
            ll bit = (num >> i) & 1LL;
            if(!temp -> containKye(bit)){
                temp -> put(bit, new Node());
            }
            temp = temp -> get(bit);
        }
    }
    ll maxXor(ll x){
        Node *temp = root;
        ll mxXor = 0;
        for(long long i = 31; i >= 0; i--){
            long long bit = (x >> i) & 1LL;
            if(temp -> containKye(1 - bit)){
                mxXor += (1LL << i);
                temp = temp -> get(1 - bit);
            }
            else{
                temp = temp -> get(bit);
            }
        }
        return mxXor;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2){
    ll ans = 0;
    Trie T;
    for(ll i = 0; i < n; i++){
        T.insert(arr1[i]);
    }
    for(ll i = 0; i < m; i++){
        ans = max(ans, T.maxXor(arr2[i]));
    }
    return (int)ans;
} 