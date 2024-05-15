#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 100005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

int arr[mx];
int tree[mx * 4];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int l, int r, int a, int b){ // here a and b are the range of the query                                           // l and r are the range of the tree
    if(a > r || b < l) return INT_MAX;           // here l, r are the range of the tree
    if(l >= a && r <= b) return tree[node];
    int mid = (l + r) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    int p1 = query(left, l, mid, a, b);
    int p2 = query(right, mid + 1, r, a, b);
    return min(p1, p2);
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        //cout << l << " " << r << endl;
        cout << query(1, 1, n, l, r) << endl;
    }
    // for(int i = 1; i <= 10; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
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