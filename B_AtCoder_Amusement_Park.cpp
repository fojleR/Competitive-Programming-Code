#include <bits/stdc++.h> 

using namespace std;
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
    ll maxXor(ll x, ll y){
        Node *temp = root;
        ll mxXor = 0;
        ll tt = 0;
        cout << x << " " << y << endl;
        for(long long i = 31; i >= 0; i--){
            cout << i << " ";
            long long bit = (x >> i) & 1LL;
            // cout << 1 - bit << endl;
            if((1 - bit)){
                if((tt + (1LL << i)) > y){
                    cout << i << endl;
                    temp = temp -> get(bit);
                    continue;
                }
            }
            if(temp -> containKye(1 - bit)){
                if((1 - bit)){
                    tt += (1LL << i);
                }
                mxXor += (1LL << i);
                temp = temp -> get(1 - bit);
            }
            else{
                if(bit){
                    tt += (1LL << i);
                }
                temp = temp -> get(bit);
            }
        }
        cout << endl;
        return mxXor;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector< int > ans;
    Trie T;
    for(auto x : arr){
        T.insert(x);
    }
    for(auto x: queries){
        int tm = T.maxXor(x[0], x[1]);
        if(tm == 0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(tm);
        }
    }
    return ans;
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector< int > arr(n);
    for(auto &x : arr) cin >> x;
    vector< vector< int > > queries(q, vector< int >(2));
    for(auto &x : queries){
        int xx, yy;
        cin >> xx >> yy;
        x[0] = xx;
        x[1] = yy;
    }
    for(auto x: arr) cout << x << " ";
    cout << endl;
    vector <int > ans = maxXorQueries(arr, queries);
    for(auto x : ans) cout << x << " ";
    cout << endl;
}


int main(){
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}


