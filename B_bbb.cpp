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

vector< ll > lst[mx];

void solve(){
    ll n, m;
    cin >> n >> m;
    vector< ll > v(n + 1);
    for(ll i = 1; i <= n; i++){
        cin >> v[i];
    }
    ll arr[n + 1] = {0};
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        lst[x].pb(y);
        lst[y].pb(x);
        arr[x] += v[y];
        arr[y] += v[x];
    }
    deque< pair< ll, ll > > dq;
    for(ll i = 1; i <= n; i++){
        dq.pb({arr[i], i});
    }
    sort(dq.begin(), dq.end());
    ll ans = 0;
    bool out[n + 1] = {0};
    // for(ll i = 1; i <= n; i++){
    //     cout << arr[i] << " ";
    // }
    while(dq.size()){
        ll x = dq.front().second;
        ll xx = dq.front().first;
        // cout << x << " " << 
        dq.pop_front();
        for(auto y : lst[x]){
            if(out[y]){
                arr[x] -= v[y];
            }
        }
        out[x] = 1;
        ans = max(ans, arr[x]);
    }
    cout << ans << endl;
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