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

ll n, q;
vector< ll > gg[mx];
ll arr[mx];
ll euler[2 * mx];
ll spos[mx];
ll epos[mx];
ll idx = 1;


ll ar[mx];
ll tree[mx*8];
 
void build(ll node, ll l, ll r){
    if(l == r){
        if(epos[euler[l]] == l){
            tree[node] -= arr[euler[l]];
        }
        else{
            tree[node] += arr[euler[l]];
        }
        //cout << l << "  " << tree[node] << endl;
        return;
    }
    ll mid = (l + r) / 2;
    ll Lnode = 2 * node;
    ll Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = tree[Lnode] + tree[Rnode];
    // cout << l << " " << r << " " << tree[node] << endl;
}

void update(ll node, ll l, ll r, ll a, ll b, ll v){
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        tree[node] = v;
        return;
    }
    ll mid = (l + r) / 2;
    ll Lnode = 2 * node;
    ll Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b, v);
    update(Rnode, mid + 1, r, a, b, v);
    tree[node] = tree[Lnode] + tree[Rnode];
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
    return p + q;
}

void dfs(ll u, ll p){
    euler[idx++] = u;
    for(auto v : gg[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    euler[idx++] = u;
}

void solve(){
    cin >> n >> q;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        gg[x].push_back(y);
        gg[y].push_back(x);
    }
    dfs(1, -1);
    for(ll i = 1; i <= 2*n; i++){
        ll x = euler[i];
        if(spos[x] == 0){
            spos[x] = i;
        }
        else{
            epos[x] = i;
        }
    }
    build(1, 1, 2*n);
    while(q--){
        ll ch;
        cin >> ch;
        if(ch == 1){
            ll x, v;
            cin >> x >> v;
            update(1, 1, 2*n, spos[x], spos[x], v);
            update(1, 1, 2*n, epos[x], epos[x], -v);
        }
        else{
            ll x; 
            cin >> x;
            // cout << spos[1] << " " << spos[x] << endl;
            ll ans = query(1, 1, 2*n, spos[1], spos[x]);
            cout << ans << endl;
        }
    }

}


int main(){
    fast
    ll t = 1;
    //cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}