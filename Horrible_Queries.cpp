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

int ar[mx];
ll tree[mx*4];
ll lazy[mx*4];
 
void build(int node, int l, int r){
    if(l == r){
        tree[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = tree[Lnode] + tree[Rnode];
}

void update(int node, int l, int r, int a, int b, ll v){
    if(lazy[node] != 0){
        tree[node] += lazy[node] * (r - l + 1);
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
        tree[node] += v * (r - l + 1);
        if(l != r){
            lazy[2*node] += v;
            lazy[2*node+1] += v;
        }
        return;
    }
    
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b, v);
    update(Rnode, mid + 1, r, a, b, v);
    tree[node] = tree[Lnode] + tree[Rnode];
    
}
 
ll query(int node, int l, int r, int a, int b){
    if(lazy[node] != 0){
        tree[node] += lazy[node] * (r - l + 1);
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
        return tree[node];
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    ll p = query(Lnode, l, mid, a, b);
    ll q = query(Rnode, mid + 1, r, a, b);
    return p + q;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= 4 * n; i++){
        lazy[i] = 0;
    }
    build(1, 1, n);
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 0){
            int a, b;
            ll v;
            cin >> a >> b >> v;
            a++, b++;
            update(1, 1, n, a, b, v);
        }
        else{
            int a, b;
            cin >> a >> b;
            a++, b++;
            cout << query(1, 1, n, a, b) << endl;
        }
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