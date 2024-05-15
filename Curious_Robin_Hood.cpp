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
 
void build(int node, int l, int r){
    if(l == r){
        tree[node] = ar[l];
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = tree[Lnode] + tree[Rnode];
}

void update(int node, int l, int r, int a, int b, int v){
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        ar[l] = v;
        tree[node] = v;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b, v);
    update(Rnode, mid + 1, r, a, b, v);
    tree[node] = tree[Lnode] + tree[Rnode];
}
 
int query(int node, int l, int r, int a, int b){
    if(r < a || l > b){
        return 0;
    }
    if(l >= a and r <= b){
        return tree[node];
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
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 1){
            int x;
            cin >> x;
            cout << query(1, 1, n, x + 1, x + 1) << "\n";
            update(1, 1, n, x + 1, x + 1, 0);
        }
        else if(ch == 2){
            int x, v;
            cin >> x >> v;
            update(1, 1, n, x + 1, x + 1, ar[x + 1] + v);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r + 1) << "\n";
        }
    }
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": " << "\n";
        solve();
    }
    return 0;
}