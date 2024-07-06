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

ll n, a, b;
vector< ll > lis[mx];
bool vis[mx];
ll dis[mx];
ll cdis = 0;
void dfs(ll node){
    vis[node] = true;
    dis[node] = cdis;
    cdis++;
    for(auto child: lis[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    cdis--;
}

void solve(){
    cin >> n;
    cin >> a >> b;
    cdis = 0;
    for(ll i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = false;
        dis[i] = 0;
    }
    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        lis[u].pb(v);
        lis[v].pb(u);
    }
    dfs(a);
    ll disab = dis[b];
    cdis = 0;
    for(ll i = 0; i <= n; i++){
        vis[i] = false;
        dis[i] = 0;
    }
    dfs(b);
    ll mdis = 0;
    for(ll i = 1; i <= n; i++){
        //cout << i << " " << dis[i] << endl;
        mdis = max(dis[i], mdis);
    }
    ll total = mdis + (n - mdis - 1) * 2;
    ll ans = total + disab;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(lis[i].size() == 1){
            cnt++;
        }
    }
    if (cnt == 2 and n % 2 and lis[a].size() == 1 and std::find(lis[a].begin(), lis[a].end(), b) != lis[a].end()){
        cout << (n - 1) + (n - 2) << endl;
        return;
    }
    if(disab % 2){
        if(lis[a].size() > 1){
            ans++;
        }
    }

    cout << ans << endl;
    
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}