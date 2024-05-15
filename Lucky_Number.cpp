#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 1429439;
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
        tree[node] = l & 1;
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
 
int query(int node, int l, int r, int a, int b, int x){
    if(l == r){
        return l;
    }
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    if(tree[Lnode] >= x) return query(Lnode, l, mid, a, b, x);
    else return query(Rnode, mid + 1, r, a, b, x - tree[Lnode]);
}

void sieve(){
    for(int i = 1; i <= 1429431; i++){
        ar[i] = i;
    }
    build(1, 1, 1429439);
    
    // int xx = query(1, 1, 1429439, 1, 1429439, 2);
    // cout << xx << endl;
    // update(1, 1, 1429439, xx, xx, 0);
    for(int i = 2; i <= 100000; i++){
        int ithElement = query(1, 1, 1429439, 1, 1429439, i);
        //cout << ithElement << endl;
        vector< int > v;
        for(int x = ithElement; x <= 1429439; x += ithElement){
            int xx = query(1, 1, 1429439, 1, 1429439, x);
            //cout << x << " " << xx << endl;
            v.push_back(xx);
        }
        for(int xx: v){
            update(1, 1, 1429439, xx, xx, 0);
        }
    }
    // for(int i = 1; i <= 10; i++){
    //     cout << query(1, 1, 1429439, 1, 1429439, i) << " ";
    // }
    // cout << endl;
}


void solve(){
    int n;
    cin >> n;
    cout << query(1, 1, 1429439, 1, 1429439, n) << "\n";
}


int main(){
    fast
    int t = 1;
    cin >> t;
    sieve();
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}