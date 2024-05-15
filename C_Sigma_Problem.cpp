#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

struct Node{
    int data;
    struct Node *Next;
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){
            head = NULL;
        }
        void insert(int x){
            Node *newNode = new Node;
            newNode -> data = x;
            newNode -> Next = NULL;
            if(head == NULL){
                head = newNode;
            }
            else{
                Node *temp = head;
                while(temp -> Next != NULL){
                    temp = temp -> Next;
                }
                temp -> Next = newNode;
            }
        }
        void insertBegin(int x){
            Node *newNode = new Node;
            newNode -> data = x;
            newNode -> Next = head;
            head = newNode;
        }
        void insertSorted(int x){
            Node *newNode = new Node;
            newNode ->data = x;
            if(head == NULL || head -> data > x){
                newNode -> Next = head;
                head = newNode;
            }
            else{
                Node *temp = head;
                Node *pred = head -> Next;
                while(pred != NULL && pred -> data < x){
                    temp = pred;
                    pred = pred ->Next;
                }
                newNode -> Next = pred;
                temp -> Next = newNode;
            }
        }
        void deleteByPosition(int pos){
            if(pos == 1){
                head = head -> Next;
            }
            else{
                Node *temp = head;
                for(int i = 1; i < pos - 1; i++){
                    temp = temp -> Next;
                }
                temp -> Next = temp -> Next -> Next;
            }
        }
        void print(){
            Node *temp = head;
            while(temp != NULL){
                cout << temp -> data << ' ';
                temp = temp -> Next;
            }
            cout << endl;
        }
};




void solve(){
    LinkedList l;
    l.insertSorted(5);
    l.insertSorted(3);
    l.insertSorted(2);
    l.insertSorted(6);
    l.insertSorted(1);
    l.insertSorted(4);
    l.print();
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}