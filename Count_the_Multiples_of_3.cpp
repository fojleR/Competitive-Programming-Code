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
    int zero, one, two;
};

int ar[mx];
Node tree[mx*4];
int lazy[mx*4];
 
void build(int node, int l, int r){
    if(l == r){
        tree[node].zero = 1;
        tree[node].one = tree[node].two = 0;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node].one = tree[Lnode].one + tree[Rnode].one;
    tree[node].two = tree[Lnode].two + tree[Rnode].two;
    tree[node].zero = tree[Lnode].zero + tree[Rnode].zero;
}

void update(int node, int l, int r, int a, int b){
    if(lazy[node] != 0){
        //cout << "#1 " << node << endl;
        if(lazy[node] % 3 == 1){
            int temp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = temp;
        }
        else if(lazy[node] % 3 == 2){
            int temp = tree[node].zero;
            tree[node].zero = tree[node].one;
            tree[node].one = tree[node].two;
            tree[node].two = temp;
        }
        if(l != r){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        //cout << "#2 " << node << endl;
        int temp = tree[node].zero;
        tree[node].zero = tree[node].two;
        tree[node].two = tree[node].one;
        tree[node].one = temp;
        if(l != r){
            lazy[2*node] += 1;
            lazy[2*node+1] += 1;
        }
        return;
    }
    
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b);
    update(Rnode, mid + 1, r, a, b);
    tree[node].one = tree[Lnode].one + tree[Rnode].one;
    tree[node].two = tree[Lnode].two + tree[Rnode].two;
    tree[node].zero = tree[Lnode].zero + tree[Rnode].zero;
}
 
int query(int node, int l, int r, int a, int b){
    if(lazy[node] != 0){
        //cout << "#1 " << node << endl;
        if(lazy[node] % 3 == 1){
            int temp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = temp;
        }
        else if(lazy[node] % 3 == 2){
            int temp = tree[node].zero;
            tree[node].zero = tree[node].one;
            tree[node].one = tree[node].two;
            tree[node].two = temp;
        }
        if(l != r){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(r < a || l > b){
        return 0;
    }
    if(l >= a and r <= b){
        return tree[node].zero;
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    int p = query(Lnode, l, mid, a, b);
    int q = query(Rnode, mid + 1, r, a, b);
    return p + q;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < 4*n; i++){
        lazy[i] = 0;
        tree[i] = {0, 0, 0};
    }
    build(1, 1, n);
    
    for(int i = 0; i < q; i++){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 0){
            update(1, 1, n, l + 1, r + 1);
        }
        else{
            cout << query(1, 1, n, l + 1, r + 1) << endl;
        }
        //cout << tree[1].zero << " " << tree[1].one << " " << tree[1].two << endl;
        // for(int i =  1; i <= 4*n; i++){
        //     cout << i << " " << lazy[i] << endl;
        // }
    }
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": " << endl;
        solve();
    }
    return 0;
}