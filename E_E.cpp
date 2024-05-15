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

vector< pair< ll, ll > > lis[mx];
ll n, m, l;
vector< ll > ans;
bool vis[mx];
map< pair<ll, ll > , ll > mp;

void dfs(ll st, ll node, ll res, ll L){
    //cout << st << " " << node << " " << res << " " << L << endl;
    vis[node] = true;
    for(auto child: lis[node]){
        if(!vis[child.first] and child.second <= l){
            ll tm  = res;
            ll tmL = L;
            if(L - child.second < 0){
                tm++;
                tmL = l;
            }
            tmL -= child.second;
            if(mp.find({st, child.first}) == mp.end()){
                mp[{st, child.first}] = tm;
            }
            else{
                mp[{st, child.first}] = min(mp[{st, child.first}], tm);
            }
            dfs(st, child.first, tm, tmL);
        }
        else if(vis[child.first] > l){
            vis[child.first] = true;
        }
    }
}

void solve(){
    cin >> n >> m >> l;
    map< pair<ll, ll > , ll > mp2;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a > b)swap(a, b);
        if(mp2.find({a, b}) == mp2.end()){
            mp2[{a, b}] = c;
        }
        else{
            mp2[{a, b}] = min(mp2[{a, b}], c);
        }
    }
    for(auto x: mp2){
        lis[x.first.first].pb({x.first.second, x.second});
        lis[x.first.second].pb({x.first.first, x.second});
    }
    
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            vis[j] = false;
        }
        dfs(i, i, 0, l);
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         if(mp.find({i, j}) != mp.end()){
    //             cout << i << " " << j << " " <<  mp[{i, j}] << endl;
    //         }
        
    //     }
    // }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(mp.find({l, r}) == mp.end()){
            cout << -1 << endl;
        }
        else{
            cout << mp[{l, r}] << endl;
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