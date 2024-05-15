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


struct Histogram
{
    int vl, ind;
};


int arr[mx];
Histogram tree[mx*4];
int n;
 
void build(int node, int l, int r){
    if(l == r){
        tree[node].vl = arr[l];
        tree[node].ind = l;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    if(tree[Lnode].vl < tree[Rnode].vl){
        tree[node] = tree[Lnode];
    }
    else{
        tree[node] = tree[Rnode];
    }
}

 
Histogram query(int node, int l, int r, int a, int b){
    if(r < a || l > b){
        Histogram tm = {INT_MAX, -1};
        return tm;
    }
    if(l >= a and r <= b){
        return tree[node];
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    Histogram p = query(Lnode, l, mid, a, b);
    Histogram q = query(Rnode, mid + 1, r, a, b);
    if(p.vl < q.vl){
        return p;
    }
    else{
        return q;
    }
}

ll devide_and_conqure(int l, int r){
    if(l == r) return arr[l];
    if(l > r) return INT_MIN;
    int ind = query(1, 1, n, l, r).ind;
    ll vl = query(1, 1, n, l, r). vl;
    return max(devide_and_conqure(l, ind - 1), max(vl * (r - l + 1), devide_and_conqure(ind + 1, r)));
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ll ans = 0;
    build(1, 1, n);
    cout << devide_and_conqure(1, n) << endl;
    // for(int i = 1; i <= 20; i++){
    //     cout << i << " " << tree[i].vl << " " << tree[i].ind << endl;
    // }
    
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}