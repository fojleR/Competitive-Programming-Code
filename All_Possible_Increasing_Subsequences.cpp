#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { ll n=a.size(); if (!n) return cout; cout<<a[0]; for (ll i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

ll ar[mx];
ll tree[mx*4];
 
void build(ll node, ll l, ll r){
    if(l == r){
        tree[node] = 0;
        return;
    }
    ll mid = (l + r) / 2;
    ll Lnode = 2 * node;
    ll Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = (tree[Lnode] + tree[Rnode]) % mod;
}

void update(ll node, ll l, ll r, ll a, ll b, ll v){
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        ar[l] = v;
        tree[node] = v;
        return;
    }
    ll mid = (l + r) / 2;
    ll Lnode = 2 * node;
    ll Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b, v);
    update(Rnode, mid + 1, r, a, b, v);
    tree[node] = (tree[Lnode] + tree[Rnode]) % mod;
}
 
ll query(ll node, ll l, ll r, ll a, ll b){
    if(r < a || l > b){
        return 0;
    }
    if(l >= a and r <= b){
        return tree[node];
    }
 
    ll  mid = (l + r) / 2;
    ll Lnode = 2 * node;
    ll Rnode = Lnode + 1;
    ll p = query(Lnode, l, mid, a, b);
    ll q = query(Rnode, mid + 1, r, a, b);
    return (p + q) % mod;
}

bool cmp(pair< ll, ll > a, pair< ll, ll > b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> ar[i];
    }
    vector< pair< ll, ll > > v;
    build(1, 1, n);
    for(ll i = 1; i <= n; i++){
        v.push_back({ar[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    for(ll i = 0; i < n; i++){
        ll ind = v[i].second;
        ll vl = query(1, 1, n, 1, ind);
        // cout << ind << " " << vl << endl;
        vl += 1;
        vl %= mod;
        update(1, 1, n, ind, ind, vl);
    }
    cout << tree[1] << endl;
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}